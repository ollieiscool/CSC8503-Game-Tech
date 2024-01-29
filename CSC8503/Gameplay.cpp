#include "Gameplay.h";
#include "PushdownState.h";
#include "Debug.h";
#include "Window.h";
#include "PauseMenu.h";
#include "VictoryMenu.h"
#include "FailedMenu.h";

using namespace NCL::CSC8503;

PushdownState::PushdownResult Gameplay::OnUpdate(float dt, PushdownState** newState) {
	Debug::Print("Press U to", Vector2(0, 5), Debug::BLACK);
	Debug::Print("pause the game", Vector2(0, 10), Debug::BLACK);
	if (Window::GetKeyboard()->KeyPressed(KeyCodes::U)) {
		*newState = new PauseMenu();
		return PushdownResult::Push;
	}
	if (showFailedMenu == true) {
		*newState = new FailedMenu();
		return PushdownResult::Push;
	}
	if (showVictoryMenu == true) {
		*newState = new VictoryMenu();
		return PushdownResult::Push;
	}
	return PushdownResult::NoChange;
}