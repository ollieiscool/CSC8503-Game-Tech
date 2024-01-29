#pragma once

namespace NCL {
	namespace CSC8503 {
		class PushdownState;

		class PushdownMachine
		{
		public:
			PushdownMachine(PushdownState* initialState);
			~PushdownMachine();

			bool Update(float dt);

			PushdownState* GetActiveState() const {
				return activeState;
			}

			bool GetRestartWorld() {
				return restartWorld;
			}
			void SetRestartWorld(bool newRW) {
				restartWorld = newRW;
			}
			void SetFailedMenu(bool newFM) {
				showFailedMenu = newFM;
			}
			void SetVictoryMenu(bool newVM) {
				showVictoryMenu = newVM;
			}

		protected:
			PushdownState* activeState;
			PushdownState* initialState;

			bool restartWorld;
			bool showFailedMenu;
			bool showVictoryMenu;

			std::stack<PushdownState*> stateStack;
		};
	}
}

