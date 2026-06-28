cmake_minimum_required(VERSION 4.1)
project(serrucho)

set(CMAKE_CXX_STANDARD 20)

add_executable(serrucho main.cpp
        Biblioteca/ElementoArbolBinarioBusqueda.h
        Biblioteca/ArbolBinarioBusqueda.h
        Biblioteca/funcionesArbolBinarioBusqueda.cpp
        BibliotecaCola/funcionesCola.cpp)
