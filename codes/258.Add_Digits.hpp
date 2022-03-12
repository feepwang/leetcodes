/*
 * Question:
Given an integer num, repeatedly add all its digits until the result has only
one digit, and return it.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

namespace lc {

class Solution {
   public:
    int operator()(int num) { return addDigits(num); }

   private:
    int addDigits(int num) { return (num - 1) % 9 + 1; }
};

}  // namespace lc