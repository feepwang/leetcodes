#include <iostream>
#include <string>
#include <thread>

#include <gtest/gtest.h>

#include "1115.Print_FooBar_Alternatiely.hpp"

using std::endl;
using std::string;
using std::thread;

TEST(lc, 1115) {
    string str{};

    lc::FooBar fb{3};

    thread t1([&]() { fb.foo([&str]() { str += "foo"; }); });
    thread t2([&]() { fb.bar([&str]() { str += "bar"; }); });

    t1.join();
    t2.join();
    ASSERT_STREQ(str.c_str(), "foobarfoobarfoobar");
}