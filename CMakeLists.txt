cmake_minimum_required(VERSION 3.23)
project(Calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(Calculator main.cpp ResourceHandler.cpp ResourceHandler.h ResourceHolder.h Buttons.cpp Buttons.h Application.cpp Application.h Calculator.cpp Calculator.h)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Calculator sfml-system sfml-window sfml-graphics sfml-audio sfml-network)