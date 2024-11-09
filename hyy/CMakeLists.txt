cmake_minimum_required(VERSION 3.10)
project(MyOpenCVProject)

find_package(OpenCV REQUIRED)
add_executable(cv cv.cpp)
target_link_libraries(cv  ${OpenCV_LIBS})
