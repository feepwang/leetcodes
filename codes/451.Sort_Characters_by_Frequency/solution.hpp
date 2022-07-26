/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;

class Solution {
   public:
    // overloading operator()
    string operator()(const string& s) { return frequencySort(s); }

    // function()
    string frequencySort(string s) {
        unordered_map<char, size_t> hash;
        for (auto c : s) hash[c]++;

        string result;
        while (!hash.empty()) {
            auto iter = hash.begin();
            for (auto beg = hash.begin(), end = hash.end(); beg != end; beg++)
                if (iter->second < beg->second) iter = beg;
            result.append(iter->second, iter->first);
            hash.erase(iter);
        }

        return result;
    }
};

#endif