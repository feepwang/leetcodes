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
    // int operator()(int i,int j);

    // function()
    string maximumTime(string time) {
        if (time[0] == '?') {
            if (time[1] == '?' || time[1] == '0' || time[1] > '3')
                time[0] = '2';
            else
                time[0] = '1';
        }

        if (time[1] == '?') {
            switch (time[0]) {
                case '1':
                case '0':
                    time[1] = '9';
                    break;
                case '2':
                    time[1] = '3';
            }
        }

        if (time[3] == '?') time[3] = '5';

        if (time[4] == '?') {
            time[4] = '9';
        }
        return time;
    }
};

#endif