link_libraries(GTest::gtest_main)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} TEST_SOURCE)
add_executable(tests
        ${TEST_SOURCE})

gtest_discover_tests(tests)