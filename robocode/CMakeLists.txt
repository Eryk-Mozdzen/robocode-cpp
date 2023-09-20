cmake_minimum_required(VERSION 3.16)

project(robocode)

add_library(${PROJECT_NAME} SHARED
    "src/Robot.cpp"
)

target_include_directories(${PROJECT_NAME} PRIVATE
    "include"
)

target_compile_options(${PROJECT_NAME} PRIVATE
    -std=c++17
    -Wall
    -Wextra
    -Wpedantic
)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
