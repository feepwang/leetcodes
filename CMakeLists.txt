cmake_minimum_required(VERSION 3.15)

project(lc CXX)

set(CMAKE_CXX_STANDARD  14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(GTest REQUIRED)
if(NOT ${GTest_FOUND})
        include(FetchContent)
        FetchContent_Declare(
                googletest
                GIT_REPOSITORY https://github.com/google/googletest.git
                GIT_TAG release-1.12.1
                GIT_SHALLOW ON
        )
        # For Windows: Prevent overriding the parent project's compiler/linker settings
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        FetchContent_MakeAvailable(googletest)

        include(GoogleTest)
endif()

include_directories(codes)

add_subdirectory(tests)

add_executable(out main.cc)
