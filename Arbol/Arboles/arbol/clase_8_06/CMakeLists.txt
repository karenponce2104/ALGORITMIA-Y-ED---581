cmake_minimum_required(VERSION 4.1)
project(clase_8_06)

set(CMAKE_CXX_STANDARD 20)

add_executable(clase_8_06 main.cpp
        BibliotecaArbolBinario/ElementoArbolBinario.h
        BibliotecaArbolBinario/ArbolBinario.h
        BibliotecaArbolBinario/funcionesArbolBinario.h
        BibliotecaArbolBinario/funcionesArbolBinario.cpp)
