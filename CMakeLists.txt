cmake_minimum_required(VERSION 4.0)
project(MetodosDeOrdenamiento)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MetodosDeOrdenamiento
        main.cpp
        funciones.cpp
        funciones.h)
