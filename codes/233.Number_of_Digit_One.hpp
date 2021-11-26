/*
 * Question:
 * Given an integer n, count the total number of digit 1 appearing in all
 * non-negative integers less than or equal to n.
 *
 * ��Դ�����ۣ�LeetCode��
 * ���ӣ�https://leetcode-cn.com/problems/number-of-digit-one
 * ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <algorithm>

namespace lc {

class Solution {
   public:
    int operator()(const int& n) { return countDigitOne(n); }

   private:
    int countDigitOne(int n) {
        long long mulk = 1;
        int ans = 0;
        for (int k = 0; n >= mulk; ++k) {
            ans += (n / (mulk * 10)) * mulk + std::min(std::max(n % (mulk*10)-mulk+1,0ll),mulk);
            mulk *= 10;
        }
        return ans;
    }
};

}  // namespace lc

#endif