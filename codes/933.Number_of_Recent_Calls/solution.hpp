/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <deque>
using std::deque;

// class Solution {
//    public:
//     // overloading operator()
//     // int operator()(int i,int j);

//     // function()
//     // int add(int i,int j);
// };

class RecentCounter {
    deque<int> que;

   public:
    RecentCounter() {}

    int ping(int t) {
        que.push_back(t);
        while (t - que.front() > 3000) {
            que.pop_front();
        }
        return que.size();
    }
};

#endif