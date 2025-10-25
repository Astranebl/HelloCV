cmake_minimum_required(VERSION 3.20)
project(OpenCV_Learning LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

message(STATUS "找到OpenCV ${OpenCV_VERSION}")
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(main src/main.cpp)
target_link_libraries(main ${OpenCV_LIBS})
set_target_properties(main
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)