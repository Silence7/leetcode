/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode.cn/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (70.42%)
 * Likes:    844
 * Dislikes: 0
 * Total Accepted:    263K
 * Total Submissions: 373.5K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
 * 
 * 叶子节点 是指没有子节点的节点。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,3,null,5]
 * 输出：["1->2->5","1->3"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1]
 * 输出：["1"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目在范围 [1, 100] 内
 * -100 <= Node.val <= 100
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

#include <vector>
#include <string>

using std::vector;
using std::string;
using std::to_string;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path;

        if (nullptr == root) {
            return res;
        }

        traversal(root, path, res);

        return res;
    }

    // 递归和回溯
    void traversal(TreeNode* cur, string path, vector<string>& res) {
        path += to_string(cur->val);
        if (nullptr == cur->left && nullptr == cur->right) {
            res.push_back(path);
            return;
        }

        if (nullptr != cur->left) {
            traversal(cur->left, path + "->", res);
        }

        if (nullptr != cur->right) {
            traversal(cur->right, path + "->", res);
        }
    }
};
// @lc code=end

