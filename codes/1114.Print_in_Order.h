/*
 * Question:
 * 给你一个类：
 *
 * public class Foo {
 *   public void first() { print("first"); }
 *   public void second() { print("second"); }
 *   public void third() { print("third"); }
 * }
 *
 * 三个不同的线程 A、B、C 将会共用一个 Foo 实例。
 *
 *     线程 A 将会调用 first() 方法
 *     线程 B 将会调用 second() 方法
 *     线程 C 将会调用 third() 方法
 *
 * 请设计修改程序，以确保 second() 方法在 first() 方法之后被执行，third() 方法在
 * second() 方法之后被执行。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/print-in-order
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <functional>
#include <mutex>
#include <condition_variable>

class Foo {
public:
    Foo() {}

    void first(std::function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        flag_second = true;
        cond_second.notify_one();
    }

    void second(std::function<void()> printSecond) {
        std::unique_lock<std::mutex> lck{ mtx_second };
        cond_second.wait(lck, [this]() {return flag_second == true;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        flag_third = true;
        cond_third.notify_one();
    }

    void third(std::function<void()> printThird) {
        // printThird() outputs "third". Do not change or remove this line.
        std::unique_lock<std::mutex> lck(mtx_third);
        cond_third.wait(lck, [this]() {return flag_third;});
        printThird();
    }

private:
    std::mutex mtx_second, mtx_third;
    std::condition_variable cond_second, cond_third;
    bool flag_second = false, flag_third = false;
};
