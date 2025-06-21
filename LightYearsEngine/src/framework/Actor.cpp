#include "framework/Actor.h"
#include "Core.h"
#include "framework/Actor.h"

namespace ly
{

    Actor::Actor(World *owingWorld)
        : mHasBeganPlay(false)
    {
    }

    Actor::~Actor()
    {
    }
    void Actor::BeginPlayInternal()
    {
        if (mHasBeganPlay == false)
        {
            mHasBeganPlay = true;
            BeginPlay();
        }
    }

    void Actor::BeginPlay()
    {
        LOG("O ator foi dropado");
    }

    void Actor::Tick(float deltaTime)
    {
        LOG("O ator esta tickando %f", 1.0f / deltaTime);
    }

}
