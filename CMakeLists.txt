cmake_minimum_required(VERSION 3.15)

#set(flags "-Wall -Werror -Wextra")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_FLAGS "-g")
set(CMAKE_CXX_FLAGS " -std=c++20 -g")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
#
# execute_process(COMMAND echo ${abc})
#
# add_library()
#-std=c++20


project(IceEngine)

find_package(raylib 3.0 REQUIRED) # Requires at least version 3.0
find_library(raygui 1.0 INTERFACE)
#set(CMAKE_C_STANDARD 11) # Requires C11 standard

set(src 
Game/main.cpp
Engine/IceFactory.cpp
Engine/Object/Object.cpp
Engine/Object/DevCube.cpp
Engine/Groups/Groups.tpp
Engine/Camera/BaseCamera.cpp
Engine/Object/MeshObject.cpp
Engine/Ui/UiRenderZone.cpp
Engine/Ui/UiBaseBlock.cpp
Engine/Ui/UiBaseTextBox.cpp
Engine/Room/Room.cpp
Engine/Base/Base.cpp
Engine/Groups/BeseGroups.cpp
Engine/Import/Model/ModelManager.cpp
)

add_executable(${PROJECT_NAME} ${src})


#set(RAYGUI_ROOT ${CMAKE_CURRENT_SOURCE_DIR}"Engine/include/raygui/")
#set(RAYGUI_SRC ${RAYGUI_ROOT}/src)
target_link_libraries(${PROJECT_NAME} raylib)
#target_link_libraries(${PROJECT_NAME} raygui)



# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()