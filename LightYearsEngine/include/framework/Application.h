#pragma once
#include <SFML/Graphics.hpp>
#include <Core.h>
namespace ly
{
    class World;
    class Application
    {
    public:
        Application(unsigned int windowWidth, unsigned int windowHeight,
                    const std::string &windowTitle, std::uint32_t style);
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
        float mClearTime;
        sf::Clock mTickClock;
        sf::Clock mCleanClock;

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
