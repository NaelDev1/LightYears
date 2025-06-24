#pragma once
#include <string>

std::string GetResourceDir()
{
#ifdef NDEBUG // if in release mode
    return "assets/";
#else
    return "/Users/natanael/Documents/Estudos/EstudandoGameEngine/LightYears/LightYearsGame/assets/";
#endif
};
