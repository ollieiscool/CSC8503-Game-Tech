#pragma once
#include "GameObject.h";
namespace NCL {
	namespace CSC8503 {
		class PlayerObject : public GameObject {
		public:
			PlayerObject() {};
			~PlayerObject() {};
			void OnCollisionBegin(GameObject* otherObject) override;
			void UpdateObject(float dt, GameWorld& world) override;
			int keysCollected;
		};
	}
}