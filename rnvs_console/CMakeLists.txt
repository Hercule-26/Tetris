cmake_minimum_required(VERSION 3.5)

project(DEV4_TETRIS_D121_58124_60131 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors") # rnvs : ajout

add_subdirectory(src)
add_subdirectory(test)
