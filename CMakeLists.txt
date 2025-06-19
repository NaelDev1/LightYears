cmake_minimum_required(VERSION 3.28)

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
set(LIGHT_YEARS_ENGINE_TARGET_NAME LightYearsEngine)

add_subdirectory(LightYearsEngine)
add_subdirectory(LightYearsGame)

include(FetchContent)
set(SFML_LIB_NAME SFML)

FetchContent_Declare(
    ${SFML_LIB_NAME}
    GIT_REPOSITORY https://github.com/SFML/SFML
    GIT_TAG 3.0.0
    GIT_SHALLOW FALSE
)
FetchContent_MakeAvailable(${SFML_LIB_NAME})

target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC sfml-graphics)
target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC sfml-window)
target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC sfml-audio)
target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC sfml-system)



