cmake_minimum_required(VERSION 3.16)

project(app)

add_executable(${PROJECT_NAME}
	"src/main.cpp"
	"src/RobotFactory.cpp"
)

target_include_directories(${PROJECT_NAME} PRIVATE
    "../robocode/include"
    "include"
)

target_compile_options(${PROJECT_NAME} PRIVATE
    -std=c++17
    -Wall
    -Wextra
    -Wpedantic
)
