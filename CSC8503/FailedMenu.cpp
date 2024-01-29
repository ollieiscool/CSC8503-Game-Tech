#include "FailedMenu.h";
#include "PushdownState.h"
#include "Debug.h";
#include "Window.h";

using namespace NCL::CSC8503;

PushdownState::PushdownResult FailedMenu::OnUpdate(float dt, PushdownState** newState) {
	Debug::Print("YOU FAILED LOSER", Vector2(10, 20), Debug::RED);
	Debug::Print("YOU'RE SO RUBBISH", Vector2(10, 25), Debug::RED);
	Debug::Print("Press U to go to main menu", Vector2(10, 35), Debug::RED);
	Debug::Print("Press Escape to quit", Vector2(10, 40), Debug::RED);

	if (Window::GetKeyboard()->KeyPressed(KeyCodes::U)) {
		showFailedMenu = false;
		
		return PushdownResult::PopTwice;
	}
	if (Window::GetKeyboard()->KeyPressed(KeyCodes::ESCAPE)) {
		showFailedMenu = false;
		Window::DestroyGameWindow();
		return PushdownResult::Pop;
		
	}
	return PushdownResult::NoChange;
}