/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <queue>
#include <set>
#include <utility>

class Solution {
    int getSumOfDigits(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

   public:
    // overloading operator()
    int operator()(const int& m, const int& n, const int& k) {
        return movingCount(m, n, k);
    }

    // function()
    int movingCount(int m, int n, int k) {
        using std::pair;
        using std::queue;
        using std::set;

        if (0 == k) {
            return 1;
        }

        queue<pair<int, int>> que;
        set<pair<int, int>> st;

        que.push({0, 0});
        st.insert({0, 0});
        pair<int, int> cur;
        while (!que.empty()) {
            cur = que.front();
            que.pop();

            if (cur.first != (m - 1) &&
                st.count({cur.first + 1, cur.second}) == 0 &&
                (getSumOfDigits(cur.first + 1) + getSumOfDigits(cur.second)) <=
                    k) {
                que.push({cur.first + 1, cur.second});
                st.insert({cur.first + 1, cur.second});
            }
            if (cur.second != (n - 1) &&
                st.count({cur.first, cur.second + 1}) == 0 &&
                (getSumOfDigits(cur.first) + getSumOfDigits(cur.second + 1)) <=
                    k) {
                que.push({cur.first, cur.second + 1});
                st.insert({cur.first, cur.second + 1});
            }
        }

        return st.size();
    }
};

#endif