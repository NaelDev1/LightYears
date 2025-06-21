#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"
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
        world.lock()->SpawnActor<Actor>();
        world.lock()->SpawnActor<Actor>();
        world.lock()->SpawnActor<Actor>();
        world.lock()->SpawnActor<Actor>();
        world.lock()->SpawnActor<Actor>();
        world.lock()->SpawnActor<Actor>();
    }
}
