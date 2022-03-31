/*
 *  Question:
 * 自除数 是指可以被它包含的每一位数整除的数。
 *
 *     例如，128 是一个 自除数 ，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
 *
 * 自除数 不允许包含 0 。
 *
 * 给定两个整数 left 和 right ，返回一个列表，列表的元素是范围 [left, right]
 * 内所有的 自除数 。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/self-dividing-numbers
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>

namespace lc {
class Solution {
   public:
    std::vector<int> operator()(int left, int right) {
        return selfDividingNumbers(left, right);
    }

   private:
    std::vector<int> selfDividingNumbers(int left, int right) {
        std::vector<int> result{};
        for (int tmp{}, remainder{}; left <= right; left++) {
            tmp = left;
            if (tmp <= 9) {
                result.emplace_back(tmp);
            } else {
                while (tmp) {
                    remainder = tmp % 10;
                    if (!remainder) break;
                    if (left % remainder) break;
                    tmp /= 10;
                }
                if (!tmp) result.emplace_back(left);
            }
        }
        return result;
    }
};

}  // namespace lc
