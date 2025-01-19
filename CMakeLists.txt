cmake_minimum_required(VERSION 3.15)

set(CMAKE_C_FLAGS "-Werror -Wextra -Wall -g")
set(CMAKE_CXX_FLAGS "-Werror -Wextra -Wall -g")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
#
# execute_process(COMMAND echo ${abc})
#
# add_library()


project(IceEngine)

find_package(raylib 3.0 REQUIRED) # Requires at least version 3.0

#set(CMAKE_C_STANDARD 11) # Requires C11 standard

set(src Game/main.cpp 
Engine/IceFactory.cpp
Engine/Object/Object.cpp
Engine/Object/DevCube.cpp
Engine/Groups/Groups.tpp
Engine/Camera/BaseCamera.cpp
Engine/Camera/FpsCamera.cpp
Engine/Object/MeshObject.cpp
)

add_executable(${PROJECT_NAME} ${src})

target_link_libraries(${PROJECT_NAME} raylib)


# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()