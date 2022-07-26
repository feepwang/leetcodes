/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <string>
#include <vector>
using std::string;
using std::vector;

#define N 9

class Solution {
   public:
    // overloading operator()
    vector<vector<string>> operator()(const int& n) { return solveNQueens(n); }

    // function()
    int nums[N];      //用于记录每一次结果
    vector<int> res;  //用于存放结果

    bool valid(int nums[], int row)  //判定函数
    {
        for (int i = 0; i < row; i++) {
            if (nums[i] == nums[row] ||
                (abs((row - i)) == abs(nums[i] - nums[row])))
                return false;
        }
        return true;
    }

    void dfs(int nums[], int row,
             int n)  //递归寻解，将所有解放在res中，最后根据n的长度分开。
    {
        if (row == n)  //找到一组解
        {
            for (int i = 0; i < n; i++) {
                res.push_back(nums[i]);
            }
            return;
        }
        for (int col = 0; col < n; col++)  //遍历列
        {
            nums[row] = col;
            if (valid(nums, row))
                dfs(nums, row + 1, n);  //当前列符合条件，就看下一列。
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if (n == 1) return {{"Q"}};
        dfs(nums, 0, n);                //找到所有解，放到res中
        vector<vector<string>> s = {};  //存放结果
        int l = res.size();
        vector<string> temp;
        for (int i = 0; i < l; i++)  //用题目要求的格式输出
        {
            string t;
            for (int j = 0; j < n; j++) {
                if (j == res[i])
                    t += "Q";
                else
                    t += ".";
            }
            temp.push_back(t);
            if ((i + 1) % n == 0 && i != 0) {
                s.push_back(temp);
                temp.clear();
            }
        }
        return s;
    }
};

#endif