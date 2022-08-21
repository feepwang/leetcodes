//
// Created by feep on 2022/8/21.
//

/*
 * Question:
 * 给你一个字符串 sentence 作为句子并指定检索词为 searchWord ，其中句子由若干用
 * 单个空格 分隔的单词组成。请你检查检索词 searchWord 是否为句子 sentence
 * 中任意单词的前缀。
 *
 * 如果 searchWord 是某一个单词的前缀，则返回句子 sentence
 * 中该单词所对应的下标（下标从 1 开始）。如果 searchWord
 * 是多个单词的前缀，则返回匹配的第一个单词的下标（最小下标）。如果 searchWord
 * 不是任何单词的前缀，则返回 -1 。
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <string>

#include "gtest/gtest.h"

using std::string;

namespace lc {

class Solution {
  public:
    int isPrefixOfWord(string sentence, string searchWord) {
        bool flag{true};
        for (unsigned i{}, j{}, count{1}, sz = sentence.size(),
                                          sz_w = searchWord.size();
             i < sz; ++i) {
            if (!flag) {
                if (sentence[i] == ' ') {
                    j = 0;
                    flag = true;
                }
            } else {
                if (sentence[i] == searchWord[j++]) {
                    if (j == sz_w) {
                        return count;
                    }
                } else if (sentence[i] == ' ') {
                    j = 0;
                    ++count;
                } else {
                    flag = false;
                    ++count;
                }
            }
        }
        return -1;
    }
};

} // namespace lc

TEST(lc, EXAMPLE_ONE) {
    lc::Solution sol{};

    ASSERT_EQ(sol.isPrefixOfWord("i love eating burger", "burg"), 4);
    ASSERT_EQ(sol.isPrefixOfWord("this problem is an easy problem", "pro"), 2);
    ASSERT_EQ(sol.isPrefixOfWord("i am tired", "you"), -1);
    ASSERT_EQ(sol.isPrefixOfWord("b bu bur burg burger", "burg"), 4);
}