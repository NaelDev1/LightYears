add_library(${LIGHT_YEARS_ENGINE_TARGET_NAME} STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Application.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Application.h

    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/World.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/World.h

    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Actor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Actor.h

    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Object.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Object.h

    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/MathUltility.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/MathUltility.h

    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/AssetManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/AssetManager.h

    ${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/EntryPoint.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Core.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Core.h
)

target_include_directories(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)