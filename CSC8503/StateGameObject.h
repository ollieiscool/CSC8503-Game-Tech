#pragma once
#include "GameObject.h"

namespace NCL {
    namespace CSC8503 {
        class StateMachine;
        class StateGameObject : public GameObject  {
        public:
            StateGameObject();
            ~StateGameObject();

            virtual void Update(float dt);

            void SetPlayer(GameObject* newPlayer) {
                player = newPlayer;
            }

            void SetGameWorld(GameWorld* newWorld) {
                world = newWorld;
            }

        protected:
            void MoveLeft(float dt);
            void MoveRight(float dt);
            void ChasePlayer(float dt);
            void OnCollisionBegin(GameObject* otherObject) override;

            GameWorld* world;
            bool canSeePlayer;
            GameObject* player;
            StateMachine* stateMachine;
            GameObject* SightedObject;
            float counter;
        };
    }
}
