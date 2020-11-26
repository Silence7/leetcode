/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (49.06%)
 * Likes:    917
 * Dislikes: 0
 * Total Accepted:    192K
 * Total Submissions: 391.4K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * 
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * string convert(string s, int numRows);
 * 
 * 示例 1:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 * 
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 * 
 */

// @lc code=start
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
        {
            return s;
        }

        int sSize = s.length();
        int length = 2 * numRows - 2;
        string result;
        for (int index = 0; index < numRows; index++)
        {
            if (index == 0 || index == numRows -1)
            {
                for (int loc = index; loc < sSize; loc += length)
                {
                    result.push_back(s[loc]);
                }
            }
            else
            {
                for (int left = index, right = length -index; left < sSize; left += length, right += length)
                {
                    result.push_back(s[left]);
                    if (right < sSize)
                    {
                        result.push_back(s[right]);
                    }
                }
            }
            
        }

        return result;
    }
};
// @lc code=end

