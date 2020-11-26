#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

// 1. 暴力循环 n^2
// 2. 利用hash_table n
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++) {
        	if(1 == hash.count(target - nums[i])) {
                return { hash[target - nums[i]], i};
            }
                
        	hash[nums[i]] = i;
		}

		return {-1, -1};
    }
};


int main()
{
    Solution s;
    vector<int>v {2,7,11,15};
    for ( const int i : s.twoSum(v, 9))
    {
        cout << i << endl;
    }
    cout << "Hello world!" << endl;
}