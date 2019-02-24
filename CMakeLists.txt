cmake_minimum_required(VERSION 3.13)
project(NoughtsAndCrosses)

set(CMAKE_CXX_STANDARD 17)

add_executable(NoughtsAndCrosses src/main.cpp include/interface/IRenderer.h include/Renderer.h include/interface/IPlayer.h include/Controller.h include/BoardPosition.h include/Board.h include/HumanPlayer.h src/Board.cpp src/Renderer.cpp src/HumanPlayer.cpp src/Controller.cpp include/utility.h)
target_include_directories(NoughtsAndCrosses PRIVATE include)