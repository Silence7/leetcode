/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (35.90%)
 * Likes:    4632
 * Dislikes: 0
 * Total Accepted:    738.9K
 * Total Submissions: 2.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 * 示例 4:
 * 
 * 
 * 输入: s = ""
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * s 由英文字母、数字、符号和空格组成
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0, subLength = 0, start = 0, end = 0;
        unordered_map<char, int> hash_map;
        for (;end < s.size(); end++) 
        {
            // 如果存在，刷新子串起始index，计算子串的起始长度
            if (hash_map.count(s[end]) == 1 && hash_map[s[end]] >= start)
            {
                start = hash_map[s[end]] + 1;
                subLength = end - start;
            }

            hash_map[s[end]] = end;

            // 子串长度累计
            subLength++;
            length = max(length, subLength);
        }

        return length;
    }
};
// @lc code=end

