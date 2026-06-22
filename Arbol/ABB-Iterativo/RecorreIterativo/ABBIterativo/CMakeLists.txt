cmake_minimum_required(VERSION 4.1)
project(ABBIterativo)

set(CMAKE_CXX_STANDARD 20)

add_executable(ABBIterativo main.cpp
        BibliotecaPila/ElementoPila.h
        BibliotecaPila/NodoPila.h
        BibliotecaPila/Pila.h
        BibliotecaPila/funcionesPila.h
        BibliotecaCola/Cola.h
        BibliotecaCola/funcionesCola.cpp
        Biblioteca/funcionesArbolBinarioBusqueda.cpp
        BibliotecaPila/funcionesPila.cpp)
