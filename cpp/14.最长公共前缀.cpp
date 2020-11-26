/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (38.93%)
 * Likes:    1359
 * Dislikes: 0
 * Total Accepted:    402.8K
 * Total Submissions: 1M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sSize = strs.size();
        int min = INT_MAX;
        
        if (sSize == 0)
        {
            return "";
        }

        if (sSize == 1)
        {
            return strs[0];
        }

        for (int index = 0; index < sSize; index++)
        {
            if (min > strs[index].size())
            {
                min = strs[index].size();
            }
        }

        for (int index = 1; index <= min; index++)
        {
            string compare = strs[0].substr(0, index);
            for (int loc = 1; loc < sSize; loc++)
            {
                string temp = strs[loc].substr(0, index);
                if (compare != temp)
                {
                    index--;
                    return strs[0].substr(0, index);
                }
            }
        }

        return strs[0].substr(0, min);
    }
};
// @lc code=end

