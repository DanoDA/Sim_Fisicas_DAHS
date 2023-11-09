cmake_minimum_required(VERSION 3.26)
project(ProyectoRube)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProyectoRube main.cpp)
find_package(box2d CONFIG REQUIRED)
target_link_libraries(ProyectoRube PRIVATE box2d::box2d)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(ProyectoRube PRIVATE sfml-system sfml-network sfml-graphics sfml-window)