/*
最长公共前缀
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

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

int main()
{
    Solution s;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}