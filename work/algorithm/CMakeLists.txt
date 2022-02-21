project(algorithm)
# 添加工程源文件到库
add_library(${PROJECT_NAME} src/algorithm.cpp src/list.cpp src/sort.cpp src/tree.cpp)
# 创建动态库别名
add_library(work::algorithm ALIAS ${PROJECT_NAME})
target_include_directories( ${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/include
        )