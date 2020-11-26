/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (55.54%)
 * Likes:    1014
 * Dislikes: 0
 * Total Accepted:    196.6K
 * Total Submissions: 354K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

// @lc code=start
#include <iostream>
#include<vector>
#include <map>

using namespace std;

class Solution {
public:
map<char, string> digitMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    vector<string> ans;
    string content;

    void DFS(int index, string digits) {
        if (index == digits.size())
        {
            return ans.push_back(content);
        }

        string v = digitMap[digits[index]];
        for (int i = 0; i < v.length(); i++)
        {
            content.push_back(v[i]);
            DFS(index + 1, digits);
            content.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
        {
            return ans;
        }

        DFS(0, digits);

        return ans;
    }
};
// @lc code=end

