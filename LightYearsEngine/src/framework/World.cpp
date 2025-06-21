#include "framework/Application.h"
#include "framework/World.h"
#include "Core.h"
#include "framework/Actor.h"

namespace ly
{
    World::World(Application *owningWorld) : mOwningApp{owningWorld},
                                             mBeganPlay{false},
                                             mActors{},
                                             mPendingActors{}
    {
    }

    void World::TickInternal(float deltaTime)
    {

        Tick(deltaTime);

        for (Shared<Actor> actor : mPendingActors)
        {
            mActors.push_back(actor);
            actor->BeginPlayInternal();
        }
        mPendingActors.clear();

        for (auto iter = mActors.begin(); iter != mActors.end();)
        {

            if (iter->get()->PendingDestroy())
            {
                iter = mActors.erase(iter);
            }
            else
            {
                iter->get()->Tick(deltaTime);
                ++iter;
            }
        }
    }

    void World::BeganPlay()
    {
        LOG("The world begin play");
    }
    void World::Tick(float deltaTime)
    {
        LOG("The world begin tick %f", 1.f / deltaTime);
    }

    void World::BeganPlayInternal()
    {
        if (mBeganPlay == false)
        {
            mBeganPlay = true;
            BeganPlay();
        }
    }

    World::~World()
    {
    }

}