/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <set>
#include <string>

class Solution {
   public:
    // overloading operator()
    // int operator()(int i,int j);

    // function()
    int myAtoi(std::string s) {
        std::set<char> nums{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int sum = 0;
        bool sign = true;
        auto beg = s.cbegin(), end = s.cend();
        while (beg != end) {
            while (*beg == ' ') beg++;
            if (*beg == '-') sign = false, beg++;
            if (*beg == '+') beg++;
            while (nums.count(*beg) && sum < 214748364) {
                switch (*beg) {
                    case '0':
                        sum = sum * 10;
                        break;
                    case '1':
                        sum = sum * 10 + 1;
                        break;
                    case '2':
                        sum = sum * 10 + 2;
                        break;
                    case '3':
                        sum = sum * 10 + 3;
                        break;
                    case '4':
                        sum = sum * 10 + 4;
                        break;
                    case '5':
                        sum = sum * 10 + 5;
                        break;
                    case '6':
                        sum = sum * 10 + 6;
                        break;
                    case '7':
                        sum = sum * 10 + 7;
                        break;
                    case '8':
                        sum = sum * 10 + 8;
                        break;
                    case '9':
                        sum = sum * 10 + 9;
                }
                beg++;
            }
        }
        if (!sign) sum = -sum;
        return sum;
    }
};

#endif