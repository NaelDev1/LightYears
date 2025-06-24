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
        LOG("O ator foi dropado");
    }

    void Actor::Tick(float deltaTime)
    {
        LOG("O ator esta tickando %f", 1.0f / deltaTime);
    }

    void Actor::SetTexture(const std::string &texturePath)
    {
        if (texturePath != "")
        {
            AssetManager &assetManager = AssetManager::Get();
            mTexture = assetManager.GetTexture(texturePath);
            if (mTexture.has_value() == false)
                return;
            mSprite.value().setTexture(**mTexture);
            int textureWidth = mTexture.value()->getSize().x;
            int textureHeight = mTexture.value()->getSize().y;
            mSprite.value().setTextureRect(sf::IntRect{sf::Vector2i{}, sf::Vector2i{textureWidth, textureHeight}});
        }
        else
        {

            LOG("A textura está vazia , por isso não setamos ela!");
        }
    }

    void Actor::Render(sf::RenderWindow &window)
    {
        if (mSprite.has_value())
        {
            window.draw(mSprite.value());
        }
    }

}
