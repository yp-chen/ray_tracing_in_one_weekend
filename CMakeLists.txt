cmake_minimum_required(VERSION 3.21)
project(RTWeekend)

set(CMAKE_CXX_STANDARD 17)

# 将可执行文件的输出目录设置为项目根目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

include_directories(./ RTWeekend)

add_executable(RTWeekend 
        main.cpp 
        device.h
        vec3.h
        ray.h)

target_link_libraries(RTWeekend easyx)

# 设置可执行文件的名称为 "result"
set_target_properties(RTWeekend PROPERTIES OUTPUT_NAME "z-result")
