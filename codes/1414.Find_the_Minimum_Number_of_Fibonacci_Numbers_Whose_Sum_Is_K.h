/*
 * Question:
给你数字 k ，请你返回和为 k
的斐波那契数字的最少数目，其中，每个斐波那契数字都可以被使用多次。

斐波那契数字定义为：

    F1 = 1
    F2 = 1
    Fn = Fn-1 + Fn-2 ， 其中 n > 2 。

数据保证对于给定的 k ，一定能找到可行解。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>

namespace lc {

class Solution {
   public:
    int operator()(int k) { return findMinFibonacciNumbers(k); }

   private:
    int findMinFibonacciNumbers(int k) {
        std::vector<int> f;
        f.emplace_back(1);
        int a = 1, b = 1;
        while (a + b <= k) {
            int c = a + b;
            f.emplace_back(c);
            a = b;
            b = c;
        }
        int ans = 0;
        for (int i = f.size() - 1; i >= 0 && k > 0; i--) {
            int num = f[i];
            if (k >= num) {
                k -= num;
                ans++;
            }
        }
        return ans;
    }
};

}  // namespace lc