cmake_minimum_required(VERSION 4.0)
project(PilasAlturas)

set(CMAKE_CXX_STANDARD 20)

add_executable(PilasAlturas main.cpp
        BibliotecaPila/funcionesPila.cpp)
