#pragma once
#include "GameObject.h";
#include "fileReader.h";
namespace NCL {
	namespace CSC8503 {
		class SillyGooseObject : public GameObject {
		public:
			SillyGooseObject();
			~SillyGooseObject();
			void OnCollisionBegin(GameObject* otherObject) override;
			void OnCollisionStay(GameObject* otherObject) override;
			void UpdateObject(float dt, GameWorld& world) override;
		protected:
			fileReader* reader;
			float x;
			float y;
			float z;
		};
	}
}