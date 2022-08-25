/*
 * Question:
Hercy wants to save money for his first car. He puts money in the Leetcode bank
every day.

He starts by putting in $1 on Monday, the first day. Every day from Tuesday to
Sunday, he will put in $1 more than the day before. On every subsequent Monday,
he will put in $1 more than the previous Monday. Given n, return the total
amount of money he will have in the Leetcode bank at the end of the nth day.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/calculate-money-in-leetcode-bank
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

namespace lc {

class Solution {
   public:
    int operator()(int n) { return totalMoney(n); }

   private:
    int totalMoney(int n) {
        int a = n / 7, b = n % 7;
        return (49 + a * 7) * a / 2 + (a * 2 + b + 1) * b / 2;
    }
};

}  // namespace lc