/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 *
 * https://leetcode.cn/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (61.68%)
 * Likes:    521
 * Dislikes: 0
 * Total Accepted:    194.6K
 * Total Submissions: 315.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定二叉树的根节点 root ，返回所有左叶子之和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入: root = [3,9,20,null,null,15,7] 
 * 输出: 24 
 * 解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: root = [1]
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 节点数在 [1, 1000] 范围内
 * -1000 <= Node.val <= 1000
 * 
 * 
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
#include "include/TreeNode.h" // 提交注释, 本地调试使用

#include <stack>
using std::stack;

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // return recursionTraversal(root);
        return iterationTraversal(root);
    }

    // 递归
    int recursionTraversal(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        int value = 0;
        if (nullptr != root->left && nullptr == root->left->left && nullptr == root->left->right) {
            value = root->left->val;
        }

        return value + recursionTraversal(root->left) + recursionTraversal(root->right);
    }

    // 迭代, 前序+栈
    int iterationTraversal(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        stack<TreeNode*> stk;
        stk.push(root);
        int value = 0;
        
        while (!stk.empty()) {
            TreeNode* cur = stk.top(); stk.pop();
            if (nullptr != cur->left && nullptr == cur->left->left && nullptr == cur->left->right) {
                value += cur->left->val;
            }

            if (nullptr != cur->right) {
                stk.push(cur->right);
            }

            if (nullptr != cur->left) {
                stk.push(cur->left);
            }
        }

        return value;
    }
};
// @lc code=end

