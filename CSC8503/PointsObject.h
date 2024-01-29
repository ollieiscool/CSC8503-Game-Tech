#pragma once
#include "GameObject.h";
#include "fileReader.h";
namespace NCL {
	namespace CSC8503 {
		class PointsObject : public GameObject {
		public:
			PointsObject();
			~PointsObject();
			void OnCollisionBegin(GameObject* otherObject) override;
			void UpdateObject(float dt, GameWorld& world) override;
		protected:
			int worth = 10;
			fileReader* reader;
		};
	}
}
