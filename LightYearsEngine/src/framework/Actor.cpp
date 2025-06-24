#include "framework/Actor.h"
#include "Core.h"
#include "framework/Actor.h"
#include "SFML/Graphics.hpp"
#include "framework/AssetManager.h"

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
            int textureWidth = tex->getSize().x;
            int textureHeight = tex->getSize().y;
            mSprite.emplace(**mTexture, sf::IntRect{sf::Vector2i{0, 0}, sf::Vector2i{textureWidth, textureHeight}});
        }
        else
        {

            LOG("The texture is empty");
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
