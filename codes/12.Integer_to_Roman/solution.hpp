/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <string>
using std::string;

class Solution {
   public:
    // overloading operator()
    string operator()(const int& num) { return intToRoman(num); }

    // function()
    string intToRoman(int num) {
        const string thousands[] = {"", "M", "MM", "MMM"};
        const string hundreds[] = {"",  "C",  "CC",  "CCC",  "CD",
                                   "D", "DC", "DCC", "DCCC", "CM"};
        const string tens[] = {"",  "X",  "XX",  "XXX",  "XL",
                               "L", "LX", "LXX", "LXXX", "XC"};
        const string ones[] = {"",  "I",  "II",  "III",  "IV",
                               "V", "VI", "VII", "VIII", "IX"};

        return thousands[num / 1000] + hundreds[num % 1000 / 100] +
               tens[num % 100 / 10] + ones[num % 10];
    }
};

#endif