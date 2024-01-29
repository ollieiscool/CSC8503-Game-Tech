#include "PushdownMachine.h"
#include "PushdownState.h"

using namespace NCL::CSC8503;

PushdownMachine::PushdownMachine(PushdownState* initialState)
{
	this->initialState = initialState;
}

PushdownMachine::~PushdownMachine()
{
}

bool PushdownMachine::Update(float dt) {
	if (activeState) {
		if (showFailedMenu == true) {
			activeState->SetFailedMenu(true);
			showFailedMenu = false;
		}
		if (showVictoryMenu == true) {
			activeState->SetVictoryMenu(true);
			showVictoryMenu = false;
		}
		PushdownState* newState = nullptr;
		PushdownState::PushdownResult result = activeState->OnUpdate(dt, &newState);

		switch (result) {
			case PushdownState::Pop: {
				activeState->OnSleep();
				delete activeState;
				stateStack.pop();
				if (stateStack.empty()) {
					return false;
				}
				else {
					activeState = stateStack.top();
					activeState->OnAwake();
				}					
			}break;
			case PushdownState::Push: {
				activeState->OnSleep();		

				stateStack.push(newState);
				activeState = newState;
				activeState->OnAwake();
			}break;
			case PushdownState::PopTwice: {
				activeState->OnSleep();
				delete activeState;
				stateStack.pop();
				if (stateStack.empty()) {
					return false;
				}
				else {
					activeState = stateStack.top();
					activeState->OnSleep();
					delete activeState;
					stateStack.pop();
					if (stateStack.empty()) {
						return false;
					}
					else {
						activeState = stateStack.top();
						activeState->OnAwake();
					}
				}break;
			case PushdownState::ReloadWorld: {
				activeState->OnSleep();

				stateStack.push(newState);
				activeState = newState;
				activeState->OnAwake();
				restartWorld = true;
				break;
			}
			}
		}
	}
	else {
		stateStack.push(initialState);
		activeState = initialState;
		activeState->OnAwake();
	}

	return true;
}