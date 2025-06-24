#pragma once
#include "Core.h"
#include "SFML/Graphics.hpp"

namespace ly
{
    class Actor;
    class Application;
    class World
    {
    public:
        World(Application *owningApp);
        void Render(sf::RenderWindow &window);
        void TickInternal(float deltaTime);
        void BeganPlayInternal();

        virtual ~World();

        template <typename ActorType>
        Weak<ActorType> SpawnActor();

    private:
        Application *mOwningApp;
        float mBeganPlay;
        void Tick(float deltaTime);
        void BeganPlay();
        List<Shared<Actor>> mActors;
        List<Shared<Actor>> mPendingActors;
    };

    template <typename ActorType>
    Weak<ActorType> World::SpawnActor()
    {
        Shared<ActorType> newActor{new ActorType{this}};
        mPendingActors.push_back(newActor);
        return newActor;
    }

}
