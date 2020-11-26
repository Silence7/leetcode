/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (32.40%)
 * Likes:    2938
 * Dislikes: 0
 * Total Accepted:    425.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

// @lc code=start
#include <iostream>

using namespace std;

// 1. 暴力循环，O(n^3)
// 2. 中心扩散，O(n^2)
// 3. 动态规划，有点难理解
class Solution {
public:
    string longestPalindromev2(string s) {
        string result = "";
        for ( int i = 0; i < s.length(); i++){
            int tmpsize = s.length() - i;
            for ( int j = 1; j <= tmpsize; j++)
            {
                string substring = s.substr(i, j);
                if (isPalindrome(substring) && substring.size() > result.size()) {
                    result = substring;
                }
            }
        }

        return result;
    }

    bool isPalindrome(string s) {
        int start = 0, end = s.length() - 1;

        for (; start < end; start++, end--)
        {
           if (s[start] != s[end]) {
               return false;
           }
        }

        return true;
    }

    string longestPalindrome(string s) {
        int len = s.length();
        if (len <= 1) {
            return s;
        }

        string result = s.substr(0, 1);
        int maxLength = 1;
        for (int i = 0; i < len - 1; i++) {
            string leftSubstr = centerSpread(s, i, i);
            string rightSubstr = centerSpread(s, i, i + 1);
            string maxSubstr = leftSubstr.length() > rightSubstr.length() ? leftSubstr : rightSubstr;
            if (maxSubstr.length() > result.length()) {
                result = maxSubstr;
            }
        }
        
        return result;
    }

    string centerSpread(string sub, int left, int right) {
        int i = left;
        int j = right;
        int len = sub.length();
        while (i >= 0 && j < len) {
            if (sub[i] != sub[j]) {
                break;
            } 

            i--;
            j++;
        }

        return sub.substr(i + 1, j - i - 1);
    }
};
// @lc code=end

