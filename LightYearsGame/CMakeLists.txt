add_executable(${LIGHT_YEARS_GAME_TARGET_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gameFramework/GameApplication.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gameFramework/GameApplication.h

     ${CMAKE_CURRENT_SOURCE_DIR}/src/spaceship/Spaceship.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/spaceship/Spaceship.h
)
target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC ${LIGHT_YEARS_ENGINE_TARGET_NAME})
target_include_directories(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


set(RESOURCE_FOLDER_NAME "assets")
set(RESOURCE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${RESOURCE_FOLDER_NAME}")

add_custom_command(
    TARGET ${LIGHT_YEARS_GAME_TARGET_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${RESOURCE_SRC_DIR}"
    "$<TARGET_FILE_DIR:${LIGHT_YEARS_GAME_TARGET_NAME}>/${RESOURCE_FOLDER_NAME}"

    
)

configure_file(
    "config.h.in"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/config.h" ESCAPE_QUOTES
)


