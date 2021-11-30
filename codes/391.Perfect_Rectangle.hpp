/*
 * Question:
 * Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents
 * an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi)
 * and the top-right point of it is (ai, bi).
 *
 * Return true if all the rectangles together form an exact cover of a
 * rectangular region.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/perfect-rectangle
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <vector>

namespace lc {

class Solution {
   public:
    bool operator()(std::vector<std::vector<int>>& rectangles) {
        return isRectangleCover(rectangles);
    }

   private:
    bool isRectangleCover(std::vector<std::vector<int>>& rectangles) {
        

        return true;
    }
};

}  // namespace lc

#endif