/**
 * @file 1592.Rearrage_Spaces_Between_Words.h
 * @author feep (me@feep.wang)
 * @brief
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 * 给你一个字符串 text
 * ，该字符串由若干被空格包围的单词组成。每个单词由一个或者多个小写英文字母组成，并且两个单词之间至少存在一个空格。题目测试用例保证
 * text 至少包含一个单词 。
 *
 * 请你重新排列空格，使每对相邻单词之间的空格数目都 相等 ，并尽可能 最大化
 * 该数目。如果不能重新平均分配所有空格，请 将多余的空格放置在字符串末尾
 * ，这也意味着返回的字符串应当与原 text 字符串的长度相等。
 *
 * 返回 重新排列空格后的字符串 。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/rearrange-spaces-between-words
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <string>
#include <vector>
#include <sstream>

namespace lc {

class Solution {
public:
    std::string reorderSpaces(std::string text) {
        std::vector<std::string> vec;//用数组保存单词
        std::stringstream in(text);//构造string流
        std::string word,ans;
        int cnt=0;
        while(in>>word)//不断获取单词，存入vec中
        {
            vec.push_back(word);
            cnt+=word.size();//记录单词总长度
        }
        if(vec.size()==1)//如果只有一个单词，单独处理
            ans=vec[0];
        else
        {
            std::string space((text.size()-cnt)/(vec.size()-1),' ');//计算并生成单词间的空格
            for(int i=0;i<vec.size()-1;++i)//重新生成字符串，最后一个单独处理
                ans+=vec[i]+space;
            ans+=vec.back();
        }
        return ans+std::string(text.size()-ans.size(),' ');//用空格补齐并返回
    }
};

} // namespace lc
