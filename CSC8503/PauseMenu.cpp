#include "PauseMenu.h";
#include "PushdownState.h"
#include "Debug.h";
#include "Window.h";
#include "Gameplay.h"
#include "StartMenu.h";

using namespace NCL::CSC8503;

PushdownState::PushdownResult PauseMenu::OnUpdate(float dt, PushdownState** newState) {
	Debug::Print("PAUSED", Vector2(10, 20), Debug::BLACK);
	Debug::Print("Press U to return", Vector2(10, 35), Debug::BLACK);
	Debug::Print("Press I to return to menu", Vector2(10, 40), Debug::BLACK);

	if (Window::GetKeyboard()->KeyPressed(KeyCodes::U)) {
		return PushdownResult::Pop;
	}
	if (Window::GetKeyboard()->KeyPressed(KeyCodes::I)) {
		return PushdownResult::PopTwice;
	}
	return PushdownResult::NoChange;
}