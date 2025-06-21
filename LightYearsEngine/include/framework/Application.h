#pragma once
#include <SFML/Graphics.hpp>
#include <Core.h>
namespace ly
{
    class World;
    class Application
    {
    public:
        Application();
        void Run();

        template <typename WorldType>
        Weak<WorldType> LoadWord();

    private:
        void TickInternal(float deltaTime);
        void RenderInternal();

        virtual void Render();
        virtual void Tick(float deltaTime);

        sf::RenderWindow mWindow;
        float mTargetFrameRate;
        sf::Clock mTickClock;

        Shared<World> mCurrentWorld;
    };

    template <typename WorldType>
    Weak<WorldType> Application::LoadWord()
    {
        Shared<WorldType> newWorld{new WorldType{this}};
        mCurrentWorld = newWorld;
        return newWorld;
    }

}
