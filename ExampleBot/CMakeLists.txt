cmake_minimum_required(VERSION 3.16)

project(ExampleBot)

add_library(${PROJECT_NAME} SHARED
    "ExampleBot.cpp"
)

target_include_directories(${PROJECT_NAME} PRIVATE
    "../robocode/include"
    "include"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/../robocode/build/robocode.a"
)

target_compile_options(${PROJECT_NAME} PRIVATE
    -std=c++17
    -Wall
    -Wextra
    -Wpedantic
)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
