cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_FLAGS "-Werror -Wextra -Wall")
set(CMAKE_CXX_FLAGS "-Werror -Wextra -Wall -std=c++20")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
#
# execute_process(COMMAND echo ${abc})
#
# add_library()
#-std=c++20


project(IceEngine)

find_package(raylib 3.0 REQUIRED) # Requires at least version 3.0
#set(CMAKE_C_STANDARD 11) # Requires C11 standard

set(src 
Game/main.cpp
Engine/IceFactory.cpp
Engine/Object/Object.cpp
Engine/Object/DevCube.cpp
Engine/Groups/Groups.tpp
Engine/Camera/BaseCamera.cpp
Engine/Camera/FpsCamera.cpp
Engine/IceFactoryInit.cpp
Engine/Object/MeshObject.cpp
Engine/Ui/Ui.cpp
)

add_executable(${PROJECT_NAME} ${src})

target_link_libraries(${PROJECT_NAME} raylib)


# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()