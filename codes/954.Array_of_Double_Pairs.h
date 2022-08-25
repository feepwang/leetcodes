/*
 * Question:
 * 给定一个长度为偶数的整数数组 arr，只有对 arr 进行重组后可以满足 “对于每个 0
 * <= i < len(arr) / 2，都有 arr[2 * i + 1] = 2 * arr[2 * i]” 时，返回
 * true；否则，返回 false。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/array-of-doubled-pairs
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <algorithm>
#include <unordered_map>
#include <vector>

namespace lc {

class Solution {
   public:
    bool operator()(std::vector<int>& arr) { return canReorderDoubled(arr); }

   private:
    bool canReorderDoubled(std::vector<int>& arr) {
        std::unordered_map<int, int> cnt{};
        for (int x : arr) {
            ++cnt[x];
        }
        if (cnt[0] % 2) {
            return false;
        }

        std::vector<int> vals;
        vals.reserve(cnt.size());
        for (auto& [x, _] : cnt) {
            vals.push_back(x);
        }
        std::sort(vals.begin(), vals.end(),
                  [](int a, int b) { return abs(a) < abs(b); });

        for (int x : vals) {
            if (cnt[2 * x] < cnt[x]) {
                return false;
            }
            cnt[2 * x] -= cnt[x];
        }
        return true;
    }
};

}  // namespace lc
