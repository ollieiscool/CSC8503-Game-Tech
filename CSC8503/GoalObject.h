#pragma once
#include "GameObject.h";
#include "fileReader.h";
namespace NCL {
	namespace CSC8503 {
		class GoalObject : public GameObject {
		public:
			GoalObject();
			~GoalObject();
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