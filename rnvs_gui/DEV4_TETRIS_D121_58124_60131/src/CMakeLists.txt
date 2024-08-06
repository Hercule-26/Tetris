cmake_minimum_required(VERSION 3.5)

project(src LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")

add_executable(src
    Controller/main.cpp
    Controller/Controller.h
    Controller/Controller.cpp

    View/View.cpp
    View/view.h

    Util/Observable.h
    Util/Observer.h

    Model/TetrisInterface.h
    Model/Game.h
    Model/Game.cpp

    Model/Board.h
    Model/Board.cpp

    Model/Level.h
    Model/Level.cpp

    Model/Bag.h
    Model/Bag.cpp

    Model/Direction.h
    Model/Rotation.h

    Model/Shapes/Shape.h
    Model/Shapes/Shape.cpp
    Model/Shapes/Shapes.h
    Model/Shapes/Shapes.cpp
    Model/Shapes/Position.h
    Model/Shapes/Position.cpp

    Controller/KeyBoardInput.h
    Controller/KeyBoardInput.cpp

)
