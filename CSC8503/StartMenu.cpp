#include "StartMenu.h";
#include "PushdownState.h"
#include "Debug.h";
#include "Window.h";
#include "Gameplay.h"

using namespace NCL::CSC8503;

PushdownState::PushdownResult StartMenu::OnUpdate(float dt, PushdownState** newState) {
	Debug::Print("Welcome to the best gaming", Vector2(10, 20), Debug::BLACK);
	Debug::Print("experience of your life.", Vector2(10, 25), Debug::BLACK);
	Debug::Print("Press U to begin", Vector2(10, 35), Debug::BLACK);
	Debug::Print("Press Escape to quit", Vector2(10, 40), Debug::BLACK);

	if (Window::GetKeyboard()->KeyPressed(KeyCodes::U)) {
		*newState = new Gameplay();
		
		return PushdownResult::ReloadWorld;
	}
	if (Window::GetKeyboard()->KeyPressed(KeyCodes::ESCAPE)) {
		return PushdownResult::Pop;
		Window::DestroyGameWindow();
	}
	return PushdownResult::NoChange;
}
