#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"
#include "framework/Object.h"
#include "Core.h"

ly::Application *GetApplication()
{
    return new ly::GameApplication();
}

namespace ly
{
    GameApplication::GameApplication()
    {
        Weak<World> world = LoadWord<World>();
        world.lock()->SpawnActor<Actor>();
        mActorToDestroy = world.lock()->SpawnActor<Actor>();

        mCounterTime = 0;
    };

    void GameApplication::Tick(float deltaTime)
    {
        mCounterTime += deltaTime;
        if (mCounterTime > 2.f)
        {

            if (mActorToDestroy.expired() == false)
            {
                mActorToDestroy.lock()->Destroy();
            }
        }

        LOG("Is making the tick by the override")
    }

}
