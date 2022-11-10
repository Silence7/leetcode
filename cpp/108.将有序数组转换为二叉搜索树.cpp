/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (77.18%)
 * Likes:    1185
 * Dislikes: 0
 * Total Accepted:    312.4K
 * Total Submissions: 404.8K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
 * 
 * 高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-10,-3,0,5,9]
 * 输出：[0,-3,9,-10,null,5]
 * 解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,3]
 * 输出：[3,1]
 * 解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums 按 严格递增 顺序排列
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include "include/TreeNode.h"  // 提交注释, 本地调试使用

#include <vector>
#include <queue>

using std::vector;
using std::queue;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recursionTraversal(nums, 0, nums.size() -1);
    }

    // 递归
    TreeNode* recursionTraversal(vector<int>& nums, int left, int right) {
        // 递归退出条件
        if (left > right) {
            return nullptr;
        }

        // 取mid索引值
        // int mid = (left + right) / 2;
        int mid = left + ((right - left) / 2);
        TreeNode* root = new TreeNode(nums[mid]);

        // 构造左右节点
        root->left = recursionTraversal(nums, left, mid - 1);
        root->right = recursionTraversal(nums, mid + 1, right);

        return root;
    }

    // 迭代
    TreeNode* iterationTraversal(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(0);

        queue<TreeNode*> nodeQue;
        queue<int> leftQue;
        queue<int> rightQue;

        nodeQue.push(root);
        leftQue.push(0);
        rightQue.push(nums.size() - 1);

        while (!nodeQue.empty())
        {
            TreeNode* curNode = nodeQue.front(); nodeQue.pop();
            int left = leftQue.front(); leftQue.pop();
            int right = rightQue.front(); rightQue.pop();

            // int mid = (left + right) / 2;
            int mid = left + ((right - left) / 2);
            curNode->val = nums[mid];

            if (left <= (mid - 1)) {
                curNode->left = new TreeNode(0);
                nodeQue.push(curNode->left);
                leftQue.push(left);
                rightQue.push(mid - 1);
            }

            if (right >= (mid + 1)) {
                curNode->right = new TreeNode(0);
                nodeQue.push(curNode->right);
                leftQue.push(mid + 1);
                rightQue.push(right);
            } 
        }

        return root;
    }
};
// @lc code=end

