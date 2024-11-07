cmake_minimum_required(VERSION 3.10)
project(MyOpenCVProject)

find_package(OpenCV REQUIRED)

add_executable(yingyong2 yingyong2.cpp)
target_link_libraries(yingyong2  ${OpenCV_LIBS})

