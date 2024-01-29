#include "StateGameObject.h"
#include "StateTransition.h"
#include "StateMachine.h"
#include "State.h"
#include "Debug.h"
#include "PlayerObject.h";
#include "Ray.h";
#include "CollisionDetection.h"
#include "GameWorld.h";

using namespace NCL;
using namespace CSC8503;

StateGameObject::StateGameObject() {
	counter = 0.0f;
	stateMachine = new StateMachine();

	State* stateA = new State([&](float dt)->void {
		this->MoveLeft(dt);
	}
	);
	State* stateB = new State([&](float dt)->void {
		this->MoveRight(dt);
	}
	);
	State* stateC = new State([&](float dt)->void {
		this->ChasePlayer(dt);
	}
	);

	stateMachine->AddState(stateA);
	stateMachine->AddState(stateB);
	stateMachine->AddState(stateC);

	stateMachine->AddTransition(new StateTransition(stateA, stateB, [&]()-> bool {
		return this->counter > 5.0f;
	}
	));
	stateMachine->AddTransition(new StateTransition(stateB, stateA, [&]()-> bool {
		return this->counter < 0.0f;
		}
	));

	stateMachine->AddTransition(new StateTransition(stateA, stateC, [&]()-> bool {
		return canSeePlayer == true;
	}
	));
	stateMachine->AddTransition(new StateTransition(stateC, stateA, [&]()-> bool {
		return canSeePlayer == false;
	}
	));

	stateMachine->AddTransition(new StateTransition(stateB, stateC, [&]()-> bool {
		return canSeePlayer == true;
	}
	));

}

void StateGameObject::OnCollisionBegin(GameObject* otherObject) {
	if (otherObject = dynamic_cast<PlayerObject*>(otherObject)) {
		world->SetCaught(true);
	}
}

StateGameObject::~StateGameObject() {
	delete stateMachine;
}

void StateGameObject::Update(float dt) {
	player = dynamic_cast<PlayerObject*>(player);
	Vector3 dir = (player->GetTransform().GetPosition() - this->GetTransform().GetPosition()).Normalised();
	RayCollision closestCollision;
	Ray r = Ray(this->GetTransform().GetPosition(), dir);
	if (world->Raycast(r, closestCollision, true)) {
		SightedObject = (GameObject*)closestCollision.node;
		Debug::DrawLine(this->GetTransform().GetPosition(), closestCollision.collidedAt);
		if (SightedObject == player) {
			canSeePlayer = true;
		}
		else {
			canSeePlayer = false;
		}
	}
	else {
		canSeePlayer = false;
	}
	stateMachine->Update(dt);
}

void StateGameObject::MoveLeft(float dt) {
	GetPhysicsObject()->AddForce({ -10,0,0 });
	GetPhysicsObject()->AddTorque(Vector3(0,10,0));
	counter += dt;
}

void StateGameObject::MoveRight(float dt) {
	GetPhysicsObject()->AddForce({ 10,0,0 });
	GetPhysicsObject()->AddTorque(Vector3(0, -10, 0));
	counter -= dt;
}

void StateGameObject::ChasePlayer(float dt) {
	float x = player->GetTransform().GetPosition().x - this->GetTransform().GetPosition().x;
	float z = player->GetTransform().GetPosition().z - this->GetTransform().GetPosition().z;
	GetPhysicsObject()->AddForce(Vector3(x, 0, z));
}