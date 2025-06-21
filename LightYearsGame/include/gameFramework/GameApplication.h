#pragma once
#include <framework/Application.h>
#include "framework/Actor.h"
#include "Core.h"

namespace ly
{
    class GameApplication : public Application
    {
    public:
        GameApplication();
        void Tick(float deltaTime) override;

    private:
        float mCounterTime;
        Weak<Actor> mActorToDestroy;
    };
}
