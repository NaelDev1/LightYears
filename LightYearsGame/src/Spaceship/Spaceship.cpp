#include "spaceship/Spaceship.h"
#include "framework/Actor.h"

namespace ly
{
    Spaceship::Spaceship(ly::World *owningWorld, const std::string &texturePath)
        : Actor{owningWorld, texturePath},
          mVelocity{}
    {
    }
    void Spaceship::Tick(float deltaTime)
    {
        Actor::Tick(deltaTime);
        AddActorLocationOffset(GetVelocity() * deltaTime);
    }

    void Spaceship::SetVelocity(const sf::Vector2f &newVel)
    {
        mVelocity = newVel;
    }
}
