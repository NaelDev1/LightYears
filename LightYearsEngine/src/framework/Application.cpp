#include "framework/Application.h"
#include <Core.h>
#include <framework/World.h>

namespace ly
{
    Application::Application(unsigned int windowWidth, unsigned int windowHeight,
                             const std::string &windowTitle, std::uint32_t style)
        : mWindow(sf::VideoMode({windowWidth, windowHeight}), windowTitle, style),
          mTargetFrameRate(60),
          mClearTime{2.f},
          mTickClock{},
          mCleanClock{}

    {
    }

    void Application::Run()
    {

        mTickClock.restart();

        float accumulatedTime = 0.0f;
        float targetDeltaTime = 1.0f / mTargetFrameRate;

        while (mWindow.isOpen())
        {
            while (const std::optional event = mWindow.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    mWindow.close();
            }

            accumulatedTime += mTickClock.restart().asSeconds();
            while (accumulatedTime > targetDeltaTime)
            {
                accumulatedTime -= targetDeltaTime;
                TickInternal(targetDeltaTime);
                RenderInternal();
            }
        }
    }
    void Application::TickInternal(float deltaTime)
    {
        Tick(deltaTime);
        if (mCurrentWorld)
        {
            mCurrentWorld->BeganPlayInternal();
            mCurrentWorld->TickInternal(deltaTime);
        }
    }
    void Application::RenderInternal()
    {
        mWindow.clear();
        Render();
        mWindow.display();
    }
    void Application::Render()
    {
        if (mCurrentWorld)
        {
            mCurrentWorld->Render(mWindow);
        }
    }

    void Application::Tick(float deltaTime)
    {
        LOG("the target framerate is %f", 1.f / deltaTime);
    }

}
