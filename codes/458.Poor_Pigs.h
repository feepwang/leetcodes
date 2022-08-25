/*
 * Question:
 * There are buckets buckets of liquid, where exactly one of the buckets is
 * poisonous. To figure out which one is poisonous, you feed some number of
 * (poor) pigs the liquid to see whether they will die or not. Unfortunately,
 * you only have minutesToTest minutes to determine which bucket is poisonous.
 *
 * You can feed the pigs according to these steps:
 *
 * Choose some live pigs to feed.
 * For each pig, choose which buckets to feed it. The pig will consume all the
 * chosen buckets simultaneously and will take no time. Wait for minutesToDie
 * minutes. You may not feed any other pigs during this time. After minutesToDie
 * minutes have passed, any pigs that have been fed the poisonous bucket will
 * die, and all others will survive. Repeat this process until you run out of
 * time. Given buckets, minutesToDie, and minutesToTest, return the minimum
 * number of pigs needed to figure out which bucket is poisonous within the
 * allotted time.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/poor-pigs
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <cmath>

namespace lc {

class Solution {
   public:
       int operator()(const int& buckets, const int& minutesToDie,
           const int& minutesToTest) {
        return poorPigs(buckets, minutesToDie, minutesToTest);
    }
   private:
    //  作者：AC_OIer 
    //  链接：https://leetcode-cn.com/problems/poor-pigs/solution/gong-shui-san-xie-jin-zhi-cai-xiang-xian-69fl/
    //  来源：力扣（LeetCode）
    //       著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return std::ceil(std::log(buckets) /
                         std::log(minutesToTest / minutesToDie + 1));
    }
};

}  // namespace lc

#endif