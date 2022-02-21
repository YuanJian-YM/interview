cmake_minimum_required(VERSION 3.17)
project(work)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(graph)
add_subdirectory(algorithm)
add_executable(work main.cpp)
target_link_libraries(${PROJECT_NAME}
        work::graph
        work::algorithm
        )