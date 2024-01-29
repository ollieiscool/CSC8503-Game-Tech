#include "WallObject.h";
#include "GameWorld.h";
#include "PlayerObject.h";

WallObject::WallObject() {
	reader = new fileReader();
	deleteIt = false;
	collideable = true;
}

WallObject::~WallObject() {
	delete reader;
}

void WallObject::OnCollisionBegin(GameObject* otherObject) {
	if (dynamic_cast <PlayerObject*>(otherObject) && dynamic_cast <PlayerObject*>(otherObject)->keysCollected >= 1)
	{
		deleteIt = true;
	}
}

void WallObject::UpdateObject(float dt, GameWorld& world) {
	if (deleteIt) {
		reader->Doors.erase(std::remove(reader->Doors.begin(), reader->Doors.end(), this->GetTransform().GetPosition()), reader->Doors.end());
		world.RemoveGameObject(this, true);
	}
}