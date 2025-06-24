#pragma once
#include "Core.h"
#include "SFML/Graphics.hpp"

namespace ly
{

    class AssetManager
    {
    public:
        static AssetManager &Get();
        Shared<sf::Texture> GetTexture(const std::string &pathName);
        void CleanCycle();

    protected:
        AssetManager();

    private:
        static unique<AssetManager> mAssetManager;
        Dictionary<std::string, Weak<sf::Texture>> mCacheTexture;
    };

}