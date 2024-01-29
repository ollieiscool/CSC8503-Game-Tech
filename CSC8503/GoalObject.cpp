#include "GoalObject.h";
#include "GameWorld.h";
#include "PlayerObject.h";

GoalObject::GoalObject() {
	reader = new fileReader();
	deleteIt = false;
	collideable = false;
}

GoalObject::~GoalObject() {
	delete reader;
}

void GoalObject::OnCollisionBegin(GameObject* otherObject) {
	if (dynamic_cast <PlayerObject*>(otherObject))
	{
		x = otherObject->GetTransform().GetPosition().x;
		y = otherObject->GetTransform().GetPosition().y;
		z = otherObject->GetTransform().GetPosition().z;
		this->GetTransform().SetPosition(Vector3(x, y + 5, z));
	}
}

void GoalObject::OnCollisionStay(GameObject* otherObject) {
	if (dynamic_cast <PlayerObject*>(otherObject)) {
		x = otherObject->GetTransform().GetPosition().x;
		y = otherObject->GetTransform().GetPosition().y;
		z = otherObject->GetTransform().GetPosition().z;
		this->GetTransform().SetPosition(Vector3(x, y + 1, z));
	}
}

void GoalObject::UpdateObject(float dt, GameWorld& world) {

}