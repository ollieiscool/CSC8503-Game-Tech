#include "KeyObject.h";
#include "GameWorld.h";
#include "PlayerObject.h";

KeyObject::KeyObject() {
	reader = new fileReader();
	deleteIt = false;
	collideable = false;
	pickedUp = false;
}

KeyObject::~KeyObject() {
	delete reader;
}

void KeyObject::OnCollisionBegin(GameObject* otherObject) {
	if (dynamic_cast <PlayerObject*>(otherObject))
	{
		deleteIt = true;
		dynamic_cast <PlayerObject*>(otherObject)->keysCollected += 1;
	}
	
}

void KeyObject::UpdateObject(float dt, GameWorld& world) {
	if (deleteIt) {
		pickedUp = true;
		reader->Keys.erase(std::remove(reader->Keys.begin(), reader->Keys.end(), this->GetTransform().GetPosition()), reader->Keys.end());
		world.RemoveGameObject(this, true);
	}
}