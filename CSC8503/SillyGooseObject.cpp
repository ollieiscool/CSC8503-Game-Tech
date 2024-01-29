#include "SillyGooseObject.h";
#include "GameWorld.h";
#include "PlayerObject.h";

SillyGooseObject::SillyGooseObject() {
	reader = new fileReader();
	deleteIt = false;
	collideable = false;
}

SillyGooseObject::~SillyGooseObject() {
	delete reader;
}

void SillyGooseObject::OnCollisionBegin(GameObject* otherObject) {
	if (dynamic_cast <PlayerObject*>(otherObject))
	{
		x = otherObject->GetTransform().GetPosition().x;
		y = otherObject->GetTransform().GetPosition().y;
		z = otherObject->GetTransform().GetPosition().z;
		this->GetTransform().SetPosition(Vector3(x, y + 5, z));
	}
}

void SillyGooseObject::OnCollisionStay(GameObject* otherObject) {
	if (dynamic_cast <PlayerObject*>(otherObject)) {
		x = otherObject->GetTransform().GetPosition().x;
		y = otherObject->GetTransform().GetPosition().y;
		z = otherObject->GetTransform().GetPosition().z;
		this->GetTransform().SetPosition(Vector3(x, y + 1, z));
	}
}

void SillyGooseObject::UpdateObject(float dt, GameWorld& world) {

}