#pragma once
#include <stdio.h>
#include <memory>
#include <map>
#include <unordered_map>

namespace ly
{
    template <typename T>
    using unique = std::unique_ptr<T>;

    template <typename T>
    using Shared = std::shared_ptr<T>;

    template <typename T>
    using Weak = std::weak_ptr<T>;

    template <typename T>
    using List = std::vector<T>;

    template <typename keyType, typename valueType, typename Pr = std::less<keyType>>
    using Map = std::map<keyType, valueType, Pr>;

    template <typename keyType, typename valueType, typename hasher = std::hash<keyType>>
    using Dictionary = std::unordered_map<keyType, valueType, hasher>;

// this is a macro
#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__);

}
