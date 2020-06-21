/*
最接近的三数之和

给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

 

示例：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 

提示：

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int x,int y) ///cmp函数传参的类型不是vector<int>型，是vector中元素类型,即int型
{
    return x<y;
}

class Solution {
public:

    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3)
        { 
            return 0;
        }
        
        sort(nums.begin(), nums.end(), cmp);

        int ans = nums[0] + nums[1] + nums[2];
        for (int index = 0; index < nums.size(); index++)
        {
            int start = index + 1;
            int end = nums.size() - 1;
            while (start < end)
            {
                int sum = nums[start] + nums[end] + nums[index];
                if (abs(target - ans) > abs(target - sum))
                {
                    ans = sum;
                }

                if (sum > target)
                {
                    end--;
                } 
                else if (sum < target)
                {
                    start++;
                }
                else
                {
                    return ans;
                }
                
            }
            
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v = {-1,0,1,2,-1,-4};
    cout << s.threeSumClosest(v, 0) << endl;
    for (int index = 0; index < v.size(); index++)
    {
        cout << v[index] << endl;
    }

    return 0;
}