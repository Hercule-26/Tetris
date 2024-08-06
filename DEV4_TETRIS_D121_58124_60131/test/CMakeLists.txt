cmake_minimum_required(VERSION 3.5)

add_executable(ProjectStructureTests

    tst_position.cpp
    ../src/Model/Shapes/Position.cpp
    tst_shape.cpp
    ../src/Model/Shapes/Shape.cpp
    ../src/Model/Shapes/Shapes.cpp
    tst_level.cpp
    ../src/Model/Level.cpp
)
target_include_directories(ProjectStructureTests PRIVATE
    ../DEV4_TETRIS_D121_58124_60131
)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.3.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)
#list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

target_link_libraries(ProjectStructureTests Catch2::Catch2WithMain)
