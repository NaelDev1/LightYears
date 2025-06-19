#include "framework/Application.h"
#include <iostream>

namespace ly {
    Application:: Application()
    :mWindow(sf::VideoMode({500,500}), "Game Window"),
    mTargetFrameRate(60),
    mTickClock()
    {
        
    }
    
    void Application::Run(){
        
        mTickClock.restart();
        
        float accumulatedTime = 0.0f;
        float targetDeltaTime = 1.0f / mTargetFrameRate;
        
        while(mWindow.isOpen()) {
            while(const std::optional event = mWindow.pollEvent()){
                if(event->is<sf::Event::Closed>())
                    mWindow.close();
            }
            
            accumulatedTime += mTickClock.restart().asSeconds();
            while(accumulatedTime > targetDeltaTime){
                accumulatedTime -= targetDeltaTime;
                TickInternal(targetDeltaTime);
                RenderInternal();
            }
        }
       
    }
    void Application::TickInternal(float deltaTime) {
        Tick(deltaTime);
    }
    void Application::RenderInternal(){
        mWindow.clear();
        Render();
        mWindow.display();
    }
    void Application::Render() {
        
        
        sf::RectangleShape rec = sf::RectangleShape(sf::Vector2f(120,120));
        rec.setFillColor(sf::Color::Red);
        rec.setPosition(sf::Vector2f(mWindow.getSize().x/2 - rec.getSize().x/2,
                                     mWindow.getSize().y/2 - rec.getSize().y /2) );
        mWindow.draw(rec);
        
        
       
    }
    
   
    void Application::Tick(float deltaTime) {
        std::cout << "the target framerate is " << 1.f / deltaTime << std::endl;
    }
    
}
