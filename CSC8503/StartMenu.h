#pragma once
#include "PushdownState.h"

namespace NCL {
	namespace CSC8503 {
		class StartMenu : public PushdownState {
			PushdownResult OnUpdate(float dt, PushdownState** newState) override;
		};
	}
}