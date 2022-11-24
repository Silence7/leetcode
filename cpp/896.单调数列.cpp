/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 *
 * https://leetcode.cn/problems/monotonic-array/description/
 *
 * algorithms
 * Easy (57.38%)
 * Likes:    175
 * Dislikes: 0
 * Total Accepted:    76.5K
 * Total Submissions: 133.3K
 * Testcase Example:  '[1,2,2,3]'
 *
 * 如果数组是单调递增或单调递减的，那么它是 单调 的。
 * 
 * 如果对于所有 i <= j，nums[i] <= nums[j]，那么数组 nums 是单调递增的。 如果对于所有 i <= j，nums[i]> =
 * nums[j]，那么数组 nums 是单调递减的。
 * 
 * 当给定的数组 nums 是单调数组时返回 true，否则返回 false。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,2,3]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [6,5,4,4]
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,3,2]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

#include <vector>
using std::vector;

// @lc code=start
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true, dec = true;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                inc = false;
            }

            if (nums[i] < nums[i + 1]) {
                dec = false;
            }
        }

        return inc || dec;
    }
};
// @lc code=end

