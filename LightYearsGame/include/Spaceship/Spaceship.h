#pragma once
#include "framework/Actor.h"
#include "framework/World.h"

namespace ly
{

    class Spaceship : public Actor
    {
    public:
        Spaceship(World *owningWorld, const std::string &texturePath = "");
        virtual void Tick(float deltaTime) override;
        sf::Vector2f GetVelocity() const { return mVelocity; }
        void SetVelocity(const sf::Vector2f &newVel);

    private:
        sf::Vector2f mVelocity;
    };
}