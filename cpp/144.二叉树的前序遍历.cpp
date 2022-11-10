/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (71.21%)
 * Likes:    940
 * Dislikes: 0
 * Total Accepted:    742.1K
 * Total Submissions: 1M
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,null,2,3]
 * 输出：[1,2,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1]
 * 输出：[1]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：root = [1,2]
 * 输出：[1,2]
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：root = [1,null,2]
 * 输出：[1,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [0, 100] 内
 * -100 
 * 
 * 
 * 
 * 
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
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

#include <vector>
#include <stack>

using std::vector;
using std::stack;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        // recursionTraversal(root, res);
        iterationTraversal(root, res);
        return res;
    }

    // 递归
    void recursionTraversal(TreeNode* root, vector<int>& res) {
        if (nullptr == root) {
            return;
        }

        res.push_back(root->val);
        recursionTraversal(root->left, res);
        recursionTraversal(root->right, res);
    }

    // 迭代
   void iterationTraversal(TreeNode* root, vector<int>& res) {
        if (nullptr == root) {
            return;
        }

        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode* cur = stk.top(); stk.pop();
            
            if (nullptr == cur) {
                TreeNode* cur = stk.top(); stk.pop();
                res.push_back(cur->val);
                continue;
            }

            // 中-左-右
            if (nullptr != cur->right) {
                stk.push(cur->right);
            }

            if (nullptr != cur->left) {
                stk.push(cur->left);
            }

            stk.push(cur);
            stk.push(nullptr); // 标记
        }
    }
};
// @lc code=end

