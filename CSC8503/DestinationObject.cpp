#include "DestinationObject.h";
#include "GameWorld.h";
#include "GoalObject.h";

DestinationObject::DestinationObject() {
	reader = new fileReader();
	deleteIt = false;
	collideable = false;
	delivered = false;
}

DestinationObject::~DestinationObject() {
	delete reader;
}

void DestinationObject::OnCollisionBegin(GameObject* otherObject) {
	if (dynamic_cast <GoalObject*>(otherObject))
	{
		delivered = true;
	}
}

void DestinationObject::UpdateObject(float dt, GameWorld& world) {
	if (delivered == true) {
		world.SetDelivered(true);
	}
}