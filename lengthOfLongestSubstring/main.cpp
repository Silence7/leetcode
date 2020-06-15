/*
无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
using namespace std;

// 1. 暴力循环 O(n^2)
// 2. hash_map O(n)
// 3. 用数组桶代替hash_map，【0,128】ascII字符码，按照索引大小判断是否存在

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

int main()
{
    Solution s;
    int length = s.lengthOfLongestSubstring("abcabcbb");
    cout << length << endl;

    length = s.lengthOfLongestSubstring("bbbbb");
    cout << length << endl;

    length = s.lengthOfLongestSubstring("pwwkew");
    cout << length << endl;

    length = s.lengthOfLongestSubstring(" ");
    cout << length << endl;

    length = s.lengthOfLongestSubstring("dvdf");
    cout << length << endl;
    return 0;
}