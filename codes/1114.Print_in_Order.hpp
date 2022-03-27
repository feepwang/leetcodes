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

class Foo {
   public:
    Foo() : lock_1(mtx_1, std::try_to_lock), lock_2(mtx_2, std::try_to_lock) {}

    void first(std::function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        lock_1.unlock();
    }

    void second(std::function<void()> printSecond) {
        // printSecond() outputs "second". Do not change or remove this line.
        std::lock_guard<std::mutex> guard(mtx_1);
        printSecond();
        lock_2.unlock();
    }

    void third(std::function<void()> printThird) {
        // printThird() outputs "third". Do not change or remove this line.
        std::lock_guard<std::mutex> guard(mtx_2);
        printThird();
    }

   private:
    std::mutex mtx_1, mtx_2;
    std::unique_lock<std::mutex> lock_1, lock_2;
};