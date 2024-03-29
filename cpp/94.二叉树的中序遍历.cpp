/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Easy (76.10%)
 * Likes:    1615
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,null,2,3]
 * 输出：[1,3,2]
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
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [0, 100] 内
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 */
#include "include/TreeNode.h" // 提交注释, 本地调试使用

#include <vector>
#include <stack>

using std::vector;
using std::stack;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        // stack<TreeNode*> stk;

        // TreeNode* iter = root;
        // while (nullptr != iter || !stk.empty()) {
        //     if (nullptr != iter) {
        //         stk.push(iter);
        //         iter = iter->left;
        //     } else {
        //         res.push_back(stk.top()->val);
        //         iter = stk.top()->right;
        //         stk.pop();
        //     }
        // }

        // recursionTraversal(root, res);
        iterationTraversal(root, res);

        return res;
    }

    void recursionTraversal(TreeNode* root, vector<int>& res) {
        if (nullptr == root) {
            return;
        }

        recursionTraversal(root->left, res);
        res.push_back(root->val);
        recursionTraversal(root->right, res);
    }

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

            if (nullptr != cur->right) {
                stk.push(cur->right);
            }

            stk.push(cur);
            stk.push(nullptr);

            if (nullptr != cur->left) {
                stk.push(cur->left);
            }
        }
    }
};
// @lc code=end

