#include <iostream>
#include <string>
#include <thread>

#include <gtest/gtest.h>

#include "1115.Print_FooBar_Alternatiely.hpp"

using std::endl;
using std::string;
using std::thread;

TEST(lc, One) {
    string str{};

    lc::FooBar fb{1};

    thread t1([&]() { fb.foo([&str]() { str += "foo"; }); });
    thread t2([&]() { fb.bar([&str]() { str += "bar"; }); });

    t1.join();
    t2.join();
    ASSERT_STREQ(str.c_str(), "foobar");
}

TEST(lc, Two) {
    string str{};

    lc::FooBar fb{2};

    thread t1([&]() { fb.foo([&str]() { str += "foo"; }); });
    thread t2([&]() { fb.bar([&str]() { str += "bar"; }); });

    t1.join();
    t2.join();
    ASSERT_STREQ(str.c_str(), "foobarfoobar");
}

TEST(lc, Ten) {
    string str{};

    lc::FooBar fb{10};

    thread t1([&]() { fb.foo([&str]() { str += "foo"; }); });
    thread t2([&]() { fb.bar([&str]() { str += "bar"; }); });

    t1.join();
    t2.join();
    ASSERT_STREQ(str.c_str(), "foobarfoobarfoobarfoobarfoobar"
                              "foobarfoobarfoobarfoobarfoobar");
}