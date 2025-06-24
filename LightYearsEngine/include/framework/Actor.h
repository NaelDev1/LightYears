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

        void SetActorLocation(const sf::Vector2f &newLoc);
        void SetActorRotatioin(float newRot);
        void AddActorLocationOffset(const sf::Vector2f &offsetAmt);
        void AddActorRotationOffset(float offsetAmt);
        sf::Vector2f GetActorLocation() const;
        float GetActorRotation() const;

        sf::Vector2f GetActorForwardDirection() const;
        sf::Vector2f GetActorRightDirection() const;

        int GetTextureWidth() const;
        int GetTextureHeight() const;
        void SetCenterPivot();

    private:
        bool mHasBeganPlay;
        std::optional<sf::Sprite> mSprite;
        std::optional<Shared<sf::Texture>> mTexture;
        int mTextureWidth = 0;
        int mTextureHeight = 0;
    };

}
