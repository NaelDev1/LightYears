#include "framework/Actor.h"
#include "Core.h"
#include "framework/Actor.h"
#include "SFML/Graphics.hpp"
#include "framework/AssetManager.h"
#include "framework/MathUltility.h"
namespace ly
{

    Actor::Actor(World *owingWorld, const std::string &texturePath)
        : mHasBeganPlay(false)
    {

        SetTexture(texturePath);
    }

    Actor::~Actor()
    {
    }
    void Actor::BeginPlayInternal()
    {
        if (mHasBeganPlay == false)
        {
            mHasBeganPlay = true;
            BeginPlay();
        }
    }

    void Actor::BeginPlay()
    {
        LOG("The actor has ben dropped");
    }

    void Actor::Tick(float deltaTime)
    {
        // LOG("The actor is tick %f", 1.0f / deltaTime);
    }

    void Actor::SetTexture(const std::string &texturePath)
    {
        if (texturePath != "")
        {
            AssetManager &assetManager = AssetManager::Get();
            auto tex = assetManager.GetTexture(texturePath);
            if (!tex)
                return;
            mTexture.emplace(tex);
            mTextureWidth = tex->getSize().x;
            mTextureHeight = tex->getSize().y;
            mSprite.emplace(**mTexture, sf::IntRect{sf::Vector2i{0, 0}, sf::Vector2i{mTextureWidth, mTextureHeight}});
            SetCenterPivot();
        }
        else
        {

            LOG("The texture is empty");
        }
    }

    void Actor::SetActorLocation(const sf::Vector2f &newLoc)
    {
        if (mSprite)
        {

            mSprite->setPosition(newLoc);
        }
    }
    void Actor::SetActorRotatioin(float newRot)
    {
        if (mSprite)
        {
            mSprite->setRotation(sf::degrees(newRot));
        }
    }
    void Actor::AddActorLocationOffset(const sf::Vector2f &offsetAmt)
    {
        if (mSprite)
        {
            mSprite->setPosition(GetActorLocation() + offsetAmt);
        }
    }

    void Actor::AddActorRotationOffset(float offsetAmt)
    {
        if (mSprite)
        {
            mSprite->setRotation(sf::degrees(GetActorRotation()) + sf::degrees(offsetAmt));
        }
    }

    sf::Vector2f Actor::GetActorLocation() const
    {
        if (mSprite)
        {
            return mSprite->getPosition();
        }
    }

    float Actor::GetActorRotation() const
    {
        if (mSprite)
        {
            return mSprite->getRotation().asDegrees();
        }
    }

    sf::Vector2f Actor::GetActorForwardDirection() const
    {
        return RotationToVector(GetActorRotation());
    }

    sf::Vector2f Actor::GetActorRightDirection() const
    {
        return RotationToVector(GetActorRotation() + 90.f);
    }

    int Actor::GetTextureWidth() const
    {
        return mTextureWidth;
    }

    int Actor::GetTextureHeight() const
    {
        return mTextureHeight;
    }

    void Actor::SetCenterPivot()
    {
        if (mSprite && mTexture)
        {
            sf::FloatRect bounds = mSprite->getGlobalBounds();
            mSprite->setOrigin({bounds.size.x / 2.0f, bounds.size.y / 2.0f});
        }
    }
    void Actor::Render(sf::RenderWindow &window)
    {
        if (mSprite)
        {
            window.draw(mSprite.value());
        }
    }

}
