cmake_minimum_required(VERSION 3.21)
project(COP-Final-Proj)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_OSX_ARCHITECTURES x86_64)

add_executable(COP-Final-Proj main.cpp Menu.cpp Hangman.cpp Hangman.h breakout1.cpp breakout_defs.h HangmanMenu.cpp HangmanMenu.h)
set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

target_link_libraries(COP-Final-Proj sfml-graphics sfml-window sfml-system)