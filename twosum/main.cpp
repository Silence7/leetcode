#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

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
}