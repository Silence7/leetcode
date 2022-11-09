/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode.cn/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (58.36%)
 * Likes:    2185
 * Dislikes: 0
 * Total Accepted:    721K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,2,3,4,4,3]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [1, 1000] 内
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * 
 * 进阶：你可以运用递归和迭代两种方法解决这个问题吗？
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
#include <queue>
// #include <stack>

using std::queue;
// using std::stack;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // return isMirror(root, root);
        return isIterCheck(root);
    }

    // 递归
    bool isMirror(TreeNode* r1, TreeNode* r2) {
        if (nullptr == r1 ^ nullptr == r2) {
            return false;
        }

        if (nullptr == r1 && nullptr == r2) {
            return true;
        }

        return (r1->val == r2->val) && isMirror(r1->left, r2->right) && isMirror(r1->right, r2->left);
    }

    // 迭代
    bool isIterCheck(TreeNode* root) {
        if (nullptr == root) {
            return true;
        }

        // 如队列，这里用栈平替也是可以的
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);

        while (!que.empty()) {
            TreeNode* left = que.front(); que.pop();
            TreeNode* right = que.front(); que.pop();

            if (nullptr == left && nullptr == right) {
                continue;
            }

            if (nullptr == left || nullptr == right || (left->val != right->val)) {
                return false;
            }

            que.push(left->left);
            que.push(right->right);
            que.push(left->right);
            que.push(right->left);
        }
        
        return true;
    }
};
// @lc code=end

