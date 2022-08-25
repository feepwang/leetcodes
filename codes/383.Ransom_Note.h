/*
 * Question:
 * Given two stings ransomNote and magazine, return true if ransomNote can be
 * constructed from magazine and false otherwise.
 *
 * Each letter in magazine can only be used once in ransomNote.
 *
 * ��Դ�����ۣ�LeetCode��
 * ���ӣ�https://leetcode-cn.com/problems/ransom-note
 * ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <map>
#include <string>

namespace lc {

class Solution {
   public:
    bool operator()(const std::string& ransomNote,
                    const std::string& magazine) {
        return canConstruct(ransomNote, magazine);
    }

   private:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::map<char, size_t> ransome{}, maga{};
        for (auto c : ransomNote) ransome[c]++;
        for (auto c : magazine) maga[c]++;
        for (auto p : ransome) {
            if (maga.count(p.first)) {
                if (maga[p.first] < p.second) return false;
            } else
                return false;
        }
        return true;
    }
};

}  // namespace lc

#endif