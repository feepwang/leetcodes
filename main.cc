#include <iostream>
#include <thread>

#include "1115.Print_FooBar_Alternatiely.hpp"

int main() {
    using namespace std;

    lc::FooBar fb{10};

    thread t1{[&fb]() { fb.foo([]() { cout << "foo"; }); }};
    thread t2([&fb]() { fb.bar([]() { cout << "bar"; }); });

    t1.join();
    t2.join();
    cout << std::endl;
}
