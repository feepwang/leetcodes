/*
 * Question:
You are given a stream of points on the X-Y plane. Design an algorithm that:

    Adds new points from the stream into a data structure. Duplicate points are
allowed and should be treated as different points. Given a query point, counts
the number of ways to choose three points from the data structure such that the
three points and the query point form an axis-aligned square with positive area.

An axis-aligned square is a square whose edges are all the same length and are
either parallel or perpendicular to the x-axis and y-axis.

Implement the DetectSquares class:

    DetectSquares() Initializes the object with an empty data structure.
    void add(int[] point) Adds a new point point = [x, y] to the data structure.
    int count(int[] point) Counts the number of ways to form axis-aligned
squares with point point = [x, y] as described above.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/detect-squares
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <unordered_map>
#include <vector>

namespace lc {

class DetectSqueares {
   public:
    DetectSqueares() {}

    void add(std::vector<int> point) {
        int x = point[0], y = point[1];
        cnt[y][x]++;
    }

    int count(std::vector<int> point) {
        int res = 0;
        int x = point[0], y = point[1];
        if (!cnt.count(y)) {
            return 0;
        }

        std::unordered_map<int, int>& yCnt = cnt[y];
        for (auto& [col, colCnt] : cnt) {
            if (col != y) {
                int d = col - y;
                res += (colCnt.count(x) ? colCnt[x] : 0) *
                       (yCnt.count(x + d) ? yCnt[x + d] : 0) *
                       (colCnt.count(x + d) ? colCnt[x + d] : 0);
                res += (colCnt.count(x) ? colCnt[x] : 0) *
                       (yCnt.count(x - d) ? yCnt[x - d] : 0) *
                       (colCnt.count(x - d) ? colCnt[x - d] : 0);
            }
        }
        return res;
    }

   private:
    std::unordered_map<int, std::unordered_map<int, int>> cnt;
};

}  // namespace lc