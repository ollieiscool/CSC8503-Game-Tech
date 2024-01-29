#pragma once
#include "GameObject.h";
#include "fileReader.h";
namespace NCL {
	namespace CSC8503 {
		class KeyObject : public GameObject {
		public:
			KeyObject();
			~KeyObject();
			void OnCollisionBegin(GameObject* otherObject) override;
			void UpdateObject(float dt, GameWorld& world) override;
		protected:
			fileReader* reader;
			bool pickedUp;
		};
	}
}