/*
 * Question:
 * Given an integer n, return the nth digit of the infinite integer sequence [1,
 * 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...]
 *
 * ��Դ�����ۣ�LeetCode��
 * ���ӣ�https://leetcode-cn.com/problems/nth-digit
 * ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <string>

namespace lc {

class Solution {
   public:
    int operator()(int n) { return findNthDigit(n); }

   private:
    int findNthDigit(int n) {
        int digit = 1;
        //  ��ֹ���
        //  count ����ǰλ����ʹ�õ�����λ����, start ����ǰλ�ĵ�һ����
        unsigned count = 9, start = 1;
        while (count < n) {
            // n-count ��ʣ���λ��
            n -= count;
            ++digit;
            start *= 10;
            count = digit * 9 * start;
        }
        //  
        start += (n - 1) / digit;
        return std::to_string(start)[(n - 1) % digit] - '0';
    }
};

}  // namespace lc

#endif