/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <unordered_set>
using std::unordered_set;

class Solution {
   public:
    // overloading operator()
    // int operator()(int i,int j);

    // function()
    void changeOnce(const string& beginWord,const string& endWord,unordered_set<string>& hash){
        
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        auto hash = unordered_set<string>(wordList.cbegin(), wordList.cend());

        return 0;
    }
};

#endif