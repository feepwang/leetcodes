/*
 * Questiono:
 * 给定一个正整数，检查它的二进制表示是否总是 0、1
 * 交替出现：换句话说，就是二进制表示中相邻两位的数字永不相同。
 */

namespace lc {

class Solution {
   public:
    bool operator()(int n) { return hasAlternatingBits(n); }

   private:
    bool hasAlternatingBits(int n) {
        bool flag = n & 01;
        while (n) {
            n >>= 1;
            if ((n & 01) == flag) return false;
            flag = !flag;
        }
        return true;
    }
};
}  // namespace lc
