#pragma once

namespace NCL {
	namespace CSC8503 {
		class PushdownState
		{
		public:
			enum PushdownResult {
				Push, Pop, NoChange, PopTwice, ReloadWorld
			};
			PushdownState()  {
			}
			virtual ~PushdownState() {}

			virtual PushdownResult OnUpdate(float dt, PushdownState** pushFunc) = 0;
			virtual void OnAwake() {}
			virtual void OnSleep() {}
			void SetFailedMenu(bool newFM) {
				showFailedMenu = newFM;
			}

			void SetVictoryMenu(bool newVM) {
				showVictoryMenu = newVM;
			}
			
		protected:
			bool showFailedMenu;
			bool showVictoryMenu;
		};
	}
}