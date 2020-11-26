/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (34.76%)
 * Likes:    2370
 * Dislikes: 0
 * Total Accepted:    520.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 * 
 */

// @lc code=start
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long result = 0;
        if (x == INT_MIN)
        {
            return 0;
        }

        if (x < 0)
        {
            return -reverse(-x);
        }

        while (x > 0)
        {
            int digit = x % 10;
            x /= 10;
            result = result * 10 + digit;
        }

        if (result > INT_MAX)
        {
            return 0;
        }

        return int(result);
    }
};
// @lc code=end

