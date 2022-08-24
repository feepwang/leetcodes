link_libraries(GTest::gtest_main)

add_executable(1115 1115.print_foobar_alternatively_test.cc)
add_executable(1455 1455.Check_If_a_Word_Occurs_As_a_Prefix_of_Any_Word_in_a_Sentence.cc)
add_executable(1460 1460.Make_Two_Arrays_Equal_by_Reversing_Sub-arrays.cc)

gtest_discover_tests(1115)
gtest_discover_tests(1455)
gtest_discover_tests(1460)
