cmake_minimum_required(VERSION 3.16)

project(app)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS
	Widgets
REQUIRED)

add_executable(${PROJECT_NAME}
	"src/main.cpp"
	"src/RobotFactory.cpp"
    "src/MainWindow.cpp"
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

target_link_libraries(${PROJECT_NAME}
	Qt5::Widgets
)
