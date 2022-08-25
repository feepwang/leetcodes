/*
 * Question:
 * Design a map that allows you to do the following:
 *
 * Maps a string key to a given value.
 * Returns the sum of the values that have a key with a prefix equal to a given
 * string. Implement the MapSum class:
 *
 * MapSum() Initializes the MapSum object.
 * void insert(String key, int val) Inserts the key-val pair into the map. If
 * the key already existed, the original key-value pair will be overridden to
 * the new one. int sum(string prefix) Returns the sum of all the pairs' value
 * whose key starts with the prefix.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/map-sum-pairs
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <cstddef>
#include <functional>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>

namespace lc {

// Use Trie to store the key-value pairs.
//
class MapSum {
    struct TrieNode {
        int val;
        TrieNode* next[26];
        TrieNode(int val = NULL) : val(val) {
            std::fill(next, next + 26, nullptr);
        }
    };

   public:
    MapSum() { root_ = new TrieNode(); }

    void insert(std::string key, int val) {
        int delta = val;
        if (cnt_.count(key)) {
            delta -= cnt_[key];
        }
        cnt_[key] = val;
        TrieNode* node = root_;
        for (auto c : key) {
            if (node->next[c - 'a'] == nullptr) {
                node->next[c - 'a'] = new TrieNode();
            }
            node = node->next[c - 'a'];
            node->val += delta;
        }
    }

    int sum(std::string prefix) {
        TrieNode* node = root_;
        for (auto c : prefix) {
            if (node->next[c - 'a'] == nullptr) {
                return 0;
            } else {
                node = node->next[c - 'a'];
            }
        }
        return node->val;
    }

   private:
    TrieNode* root_;
    std::unordered_map<std::string, int> cnt_;
};

// With C++17
//
// class MapSum {
//     std::map<std::string, int> m;
// public:
//     void insert(std::string key, int val) {
//         m[key]=val;
//     }

//     int sum(std::string prefix) {
//         auto i = m.lower_bound(prefix);
//         ++prefix.back();
//         auto j = m.lower_bound(prefix);
//         return std::transform_reduce(i,j,0,std::plus<>{},[](auto&&i){return
//         i.second;});
//     }
// };

}  // namespace lc

#endif