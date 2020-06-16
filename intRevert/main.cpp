/*
整数反转
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

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

int main()
{
    Solution s;
    cout << s.reverse(234) << endl;
    cout << s.reverse(-324) << endl;
}