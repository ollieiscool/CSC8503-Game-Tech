#include "VictoryMenu.h";
#include "PushdownState.h"
#include "Debug.h";
#include "Window.h";

using namespace NCL::CSC8503;

PushdownState::PushdownResult VictoryMenu::OnUpdate(float dt, PushdownState** newState) {
	Debug::Print("YOU ABSOLUTE GOD", Vector2(10, 20), Debug::GREEN);
	Debug::Print("WOW YOU'RE SO COOL", Vector2(10, 25), Debug::GREEN);
	Debug::Print("Press U to go to main menu", Vector2(10, 35), Debug::GREEN);
	Debug::Print("Press Escape to quit", Vector2(10, 40), Debug::GREEN);

	if (Window::GetKeyboard()->KeyPressed(KeyCodes::U)) {
		showVictoryMenu = false;

		return PushdownResult::PopTwice;
	}
	if (Window::GetKeyboard()->KeyPressed(KeyCodes::ESCAPE)) {
		showVictoryMenu = false;
		Window::DestroyGameWindow();
		return PushdownResult::Pop;

	}
	return PushdownResult::NoChange;
}