/*
 * Question:
 *  给你一个类：
 *
 * class FooBar {
 *   public void foo() {
 *     for (int i = 0; i < n; i++) {
 *       print("foo");
 *     }
 *   }
 *
 *   public void bar() {
 *     for (int i = 0; i < n; i++) {
 *       print("bar");
 *     }
 *   }
 * }
 *
 * 两个不同的线程将会共用一个 FooBar 实例：
 *
 *     线程 A 将会调用 foo() 方法，而
 *     线程 B 将会调用 bar() 方法
 *
 * 请设计修改程序，以确保 "foobar" 被输出 n 次。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/print-foobar-alternately
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>

namespace lc {

class FooBar {
  private:
    int n;

    std::mutex m;
    std::condition_variable cv;
    bool foo_done;

  public:
    FooBar(int n) : foo_done(false) { this->n = n; }

    void foo(std::function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lk{m};
            cv.wait(lk, [this]() { return foo_done == false; });
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            foo_done = true;
            cv.notify_one();
        }
    }

    void bar(std::function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lk(m);
            cv.wait(lk, [this]() { return foo_done; });
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            foo_done = false;
            cv.notify_one();
        }
    }
};

} // namespace lc
