cmake_minimum_required(VERSION 3.22)
project(paper_scissors_rock)

set(CMAKE_CXX_STANDARD 20)

add_executable(paper_scissors_rock src/main.cpp include/game.h include/paper_scissors_rock_game.h src/paper_scissors_rock_game.cpp include/referee.h)
add_executable(paper_scissors_rock_test include/game.h include/paper_scissors_rock_game.h src/paper_scissors_rock_game.cpp include/referee.h test/test.cpp)
