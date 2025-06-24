#include "framework/AssetManager.h"
#include "Core.h"
#include "SFML/Graphics.hpp"

namespace ly
{
    unique<AssetManager> AssetManager::mAssetManager{nullptr};
    AssetManager &AssetManager::Get()
    {
        if (!mAssetManager)
        {
            mAssetManager = unique<AssetManager>{new AssetManager};
        }
        return *mAssetManager;
    }
    AssetManager::AssetManager()
    {
    }

    Shared<sf::Texture> AssetManager::GetTexture(const std::string &pathName)
    {
        auto found = mCacheTexture.find(pathName);

        if (found != mCacheTexture.end())
        {
            if (auto tex = found->second.lock())
            {
                return tex;
            }
            else
            {
                LOG("Cleaning the texture!");
                mCacheTexture.erase(found);
            }
        }

        Shared<sf::Texture> newTexture{new sf::Texture};
        if (newTexture->loadFromFile(pathName))
        {
            LOG("Adding the texture on the cache!")
            mCacheTexture.insert({pathName, newTexture});
            return newTexture;
        }

        return nullptr;
    }
    void AssetManager::CleanCycle()
    {

        for (auto iter = mCacheTexture.begin(); iter != mCacheTexture.end();)
        {

            if (iter->second.use_count() == 1)
            {
                LOG("Cleaning the texture!");
                iter = mCacheTexture.erase(iter);
            }
            else
            {
                ++iter;
            }
        }
    }

}
