cmake_minimum_required(VERSION 3.15)

project(lc CXX)

add_executable(out main.cc)

set_target_properties(out PROPERTIES
                            CMAKE_CXX_STANDARD 17
                            CMAKE_CXX_STANDARD_REQUIRED on
                            CMAKE_CXX_EXTENSIONS on)
target_include_directories(out PUBLIC codes)
