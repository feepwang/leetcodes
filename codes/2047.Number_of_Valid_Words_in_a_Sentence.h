/*
 * Question:
句子仅由小写字母（'a' 到 'z'）、数字（'0' 到
'9'）、连字符（'-'）、标点符号（'!'、'.' 和 ','）以及空格（'
'）组成。每个句子可以根据空格分解成 一个或者多个 token ，这些 token
之间由一个或者多个空格 ' ' 分隔。

如果一个 token 同时满足下述条件，则认为这个 token 是一个有效单词：

    仅由小写字母、连字符和/或标点（不含数字）。
    至多一个 连字符 '-' 。如果存在，连字符两侧应当都存在小写字母（"a-b"
是一个有效单词，但 "-ab" 和 "ab-" 不是有效单词）。 至多一个
标点符号。如果存在，标点符号应当位于 token 的 末尾 。

这里给出几个有效单词的例子："a-b."、"afad"、"ba-c"、"a!" 和 "!" 。

给你一个字符串 sentence ，请你找出并返回 sentence 中 有效单词的数目 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-valid-words-in-a-sentence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <string>

namespace lc {

class Solution {
   public:
    int operator()(std::string sentence) { return countValidWords(sentence); }

   private:
    int countValidWords(std::string sentence) {
        char pre = ' ';
        int ans = 0;
        std::string s = sentence;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            int hyphen = 0;
            int dot = 0;
            bool valid = true;
            while (s[i] != ' ' && i < s.size()) {
                // 不含数字
                if (s[i] <= '9' && s[i] >= '0') valid = false;
                if (s[i] == '-') {
                    // 最多只有一个 划线
                    hyphen++;
                    if (i - 1 < 0 || i + 1 >= s.size()) {
                        // 不能是开始或者结尾
                        valid = false;
                    } else {
                        // 前后必须是字母 或者正好是句子结尾
                        if (s[i - 1] < 'a' || s[i - 1] > 'z') valid = false;
                        if ((s[i + 1] < 'a' || s[i + 1] > 'z') &&
                            s[i + 1] != '.')
                            valid = false;
                    }
                }
                // 分词符号只能有一个
                if (s[i] == '.' || s[i] == '!' || s[i] == ',') {
                    dot++;
                    if (i + 1 != s.size() && s[i + 1] != ' ') valid = false;
                }
                i++;
            }
            // 合法
            if (valid && dot <= 1 && hyphen <= 1) {
                ans++;
            }
        }

        return ans;
    }
};

}  // namespace lc