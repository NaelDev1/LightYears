#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"
#include "framework/Object.h"
#include "Core.h"
#include "config.h"

ly::Application *GetApplication()
{
    return new ly::GameApplication();
}

namespace ly
{
    GameApplication::GameApplication() : Application{400, 650, "LightYears", sf::Style::Close}
    {
        Weak<World> world = LoadWord<World>();
        world.lock()->SpawnActor<Actor>();
        mActorToDestroy = world.lock()->SpawnActor<Actor>();
        mActorToDestroy.lock()->SetTexture(GetResourceDir() + "SpaceShooterRedux/PNG/playerShip1_blue.png");
        int actorWidth = mActorToDestroy.lock()->GetTextureWidth();
        int actorHeight = mActorToDestroy.lock()->GetTextureHeight();
        mActorToDestroy.lock()->SetActorLocation({200.0f, 325.0f});
        mActorToDestroy.lock()->SetActorRotatioin(30.f);
        mCounterTime = 0;
    };

    void GameApplication::Tick(float deltaTime)
    {
        // mCounterTime += deltaTime;
        // if (mCounterTime > 2.f)
        // {

        //     if (mActorToDestroy.expired() == false)
        //     {
        //         mActorToDestroy.lock()->Destroy();
        //     }
        // }

        // LOG("Is making the tick by the override")
    }

}
