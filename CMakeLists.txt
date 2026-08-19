cmake_minimum_required(VERSION 3.16)
project(yams_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_library(yams_engine STATIC
    src/Dice.cpp
    src/ScoreCategory.cpp
    src/ScoreCalculator.cpp
    src/ScoreCard.cpp
)
target_include_directories(yams_engine PUBLIC include)
target_compile_options(yams_engine PRIVATE -Wall -Wextra -Wpedantic)

add_executable(yams src/main.cpp)
target_link_libraries(yams PRIVATE yams_engine)

option(YAMS_BUILD_TESTS "Compiler les tests unitaires" ON)
if(YAMS_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
