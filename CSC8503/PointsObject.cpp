#include "PointsObject.h";
#include "GameWorld.h";
#include "PlayerObject.h";

PointsObject::PointsObject() {
	reader = new fileReader();
	deleteIt = false;
	collideable = false;
}

PointsObject::~PointsObject() {
	delete reader;
}

void PointsObject::OnCollisionBegin(GameObject* otherObject) {
	if (dynamic_cast <PlayerObject*>(otherObject))
	{
		deleteIt = true;
	}
}

void PointsObject::UpdateObject(float dt, GameWorld& world) {
	if (deleteIt) {
		world.SetPointsCollected(worth);
		reader->pointPickups.erase(std::remove(reader->pointPickups.begin(), reader->pointPickups.end(), this->GetTransform().GetPosition()), reader->pointPickups.end());
		world.RemoveGameObject(this, true);
	}
}

