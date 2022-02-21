project(graph)
# 添加工程源文件到库
add_library(${PROJECT_NAME} src/graph.cpp)
# 创建动态库别名
add_library(work::graph ALIAS ${PROJECT_NAME})
target_include_directories( ${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/include
        )

#当创建动态库时
#如果源文件(例如CPP)中包含第三方头文件，但是头文件（例如hpp）中不包含该第三方文件头，采用PRIVATE。
#如果源文件和头文件中都包含该第三方文件头，采用PUBLIC。
#如果头文件中包含该第三方文件头，但是源文件(例如CPP)中不包含，采用 INTERFACE。