cmake_minimum_required(VERSION 4.0.3)

project(LightYears 
VERSION 1.0.0
 LANGUAGES C CXX
)

set(CMAKE_OSX_DEPLOYMENT_TARGET "15.3") 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#this is how to set a variable in cMake
set(LIGHT_YEARS_GAME_TARGET_NAME LightYearsGame)

add_subdirectory(LightYears)




