#pragma once
#include "framework/Object.h"
#include "SFML/Graphics.hpp"
#include "Core.h"

namespace ly
{

    class World;
    class Actor : public Object
    {
    public:
        Actor(World *owningWorld, const std::string &texturePath = "");
        void Render(sf::RenderWindow &window);
        virtual ~Actor();
        void BeginPlayInternal();
        virtual void BeginPlay();
        virtual void Tick(float deltaTime);
        void SetTexture(const std::string &texturePath);

    private:
        bool mHasBeganPlay;
        std::optional<sf::Sprite> mSprite;
        std::optional<Shared<sf::Texture>> mTexture;
    };

}
