#pragma once
#include "GameObject.h";
#include "fileReader.h";
namespace NCL {
	namespace CSC8503 {
		class WallObject : public GameObject {
		public:
			WallObject();
			~WallObject();
			void OnCollisionBegin(GameObject* otherObject) override;
			void UpdateObject(float dt, GameWorld& world) override;
			void SetWallID(int newWallID) {
				wallID = newWallID;
			}
		protected:
			fileReader* reader;
			int wallID;
		};
	}
}