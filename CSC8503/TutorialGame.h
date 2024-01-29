#include "../NCLCoreClasses/KeyboardMouseController.h"

#pragma once
#include "GameTechRenderer.h"
#ifdef USEVULKAN
#include "GameTechVulkanRenderer.h"
#endif
#include "PhysicsSystem.h"

#include "StateGameObject.h"

#include "fileReader.h";
#include "PushdownMachine.h";

namespace NCL {
	namespace CSC8503 {

		class TutorialGame		{
		public:
			TutorialGame();
			~TutorialGame();

			virtual void UpdateGame(float dt, PushdownMachine* PM);
		protected:
			void InitialiseAssets();

			void InitCamera();
			void UpdateKeys();

			void InitWorld();

			void InitLevelFromFile();

			/*
			These are some of the world/object creation functions I created when testing the functionality
			in the module. Feel free to mess around with them to see different objects being created in different
			test scenarios (constraints, collision types, and so on). 
			*/
			void InitGameExamples();

			void InitSphereGridWorld(int numRows, int numCols, float rowSpacing, float colSpacing, float radius);
			void InitMixedGridWorld(int numRows, int numCols, float rowSpacing, float colSpacing);
			void InitCubeGridWorld(int numRows, int numCols, float rowSpacing, float colSpacing, const Vector3& cubeDims);

			void InitDefaultFloor();

			bool SelectObject();
			void MoveSelectedObject();
			void DebugObjectMovement();
			void LockedObjectMovement();

			GameObject* AddPointPickup(const Vector3& position, float radius, float inverseMass = 0.0f);
			GameObject* AddWallToWorld(const Vector3& position, Vector3 dimensions, float inverseMass = 0.0f);
			GameObject* AddKeyToWorld(const Vector3& position, float radius, float inverseMass = 0.0f);
			GameObject* AddObjectiveToWorld(const Vector3& position, float radius, float inverseMass = 0.0f);
			GameObject* AddDestinationToWorld(const Vector3& position, Vector3 dimensions, float inverseMass = 0.0f);
			GameObject* AddSillyGooseToWorld(const const Vector3& position, float radius, float inverseMass = 0.0f);

			GameObject* AddFloorToWorld(const Vector3& position, const Vector3 size);
			GameObject* AddSphereToWorld(const Vector3& position, float radius, float inverseMass = 10.0f);
			GameObject* AddCubeToWorld(const Vector3& position, Vector3 dimensions, float inverseMass = 10.0f);
			GameObject* AddCapsuleToWorld(const Vector3& position, float halfHeight, float radius, float inverseMass = 10.0f);
			void BridgeConstraintTest();
			void Bridge(const Vector3& startPos, Vector3 cubeSize, int numLinks, float maxDistance, float cubeDistance, float invCubeMass);

			GameObject* AddPlayerToWorld(const Vector3& position);
			StateGameObject* AddEnemyToWorld(const Vector3& position);
			GameObject* AddBonusToWorld(const Vector3& position);

#ifdef USEVULKAN
			GameTechVulkanRenderer*	renderer;
#else
			GameTechRenderer* renderer;
#endif
			PhysicsSystem*		physics;
			GameWorld*			world;

			KeyboardMouseController controller;

			bool useGravity;
			bool inSelectionMode;

			float		forceMagnitude;

			GameObject* selectionObject = nullptr;

			Mesh*	capsuleMesh = nullptr;
			Mesh*	cubeMesh	= nullptr;
			Mesh*	sphereMesh	= nullptr;

			Texture*	basicTex	= nullptr;
			Shader*		basicShader = nullptr;

			//Coursework Meshes
			Mesh*	charMesh	= nullptr;
			Mesh*	enemyMesh	= nullptr;
			Mesh*	bonusMesh	= nullptr;
			Mesh* gooseMesh = nullptr;

			//Coursework Additional functionality	
			GameObject* lockedObject	= nullptr;
			Vector3 lockedOffset		= Vector3(0, 4, 14);
			void LockCameraToObject(GameObject* o) {
				lockedObject = o;
			}

			GameObject* objClosest = nullptr;
			GameObject* floor;
			GameObject* player;

			vector<StateGameObject*> StateObjects;

			fileReader* readFile;

			std::string pointsTally;
			std::string time;

			float count;
		};
	}
}
