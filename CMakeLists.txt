cmake_minimum_required(VERSION 3.20)

project(lc CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

find_package(GTest QUIET)
if (NOT GTest_FOUND)
    message(STATUS "GTest NOT FOUND IN SYSTEM ENVIRONMENT")
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
endif ()

include_directories(codes)

add_subdirectory(tests)
