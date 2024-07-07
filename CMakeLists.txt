cmake_minimum_required(VERSION 3.28)
project(FlowField)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        FlowField
        src/main.cpp
        include/main.hpp
        include/PerlinNoise.hpp
        src/PerlinNoise.cpp
        include/Random.hpp
        src/Random.cpp
)

target_link_libraries(FlowField sfml-graphics sfml-window sfml-system)