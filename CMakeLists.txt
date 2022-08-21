cmake_minimum_required(VERSION 3.15)

project(lc CXX)

enable_testing()

set(CMAKE_CXX_STANDARD  14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(codes)

add_subdirectory(dep/googletest)
find_package(GTest)
add_subdirectory(tests)

add_executable(out main.cc)
