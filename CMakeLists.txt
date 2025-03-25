cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SpacePhysicsSim)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(SpacePhysicsSim src/main.cpp src/Renderer.cpp src/World.cpp)

# Find raylib package
find_package(raylib REQUIRED)
target_link_libraries(SpacePhysicsSim PRIVATE raylib)

