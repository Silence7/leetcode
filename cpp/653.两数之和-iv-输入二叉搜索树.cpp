/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入二叉搜索树
 *
 * https://leetcode.cn/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (63.43%)
 * Likes:    442
 * Dislikes: 0
 * Total Accepted:    103.9K
 * Total Submissions: 163.8K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * 给定一个二叉搜索树 root 和一个目标结果 k，如果二叉搜索树中存在两个元素且它们的和等于给定的目标结果，则返回 true。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: root = [5,3,6,2,4,null,7], k = 9
 * 输出: true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: root = [5,3,6,2,4,null,7], k = 28
 * 输出: false
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 二叉树的节点个数的范围是  [1, 10^4].
 * -10^4 <= Node.val <= 10^4
 * 题目数据保证，输入的 root 是一棵 有效 的二叉搜索树
 * -10^5 <= k <= 10^5
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

#include <unordered_set>
using std::unordered_set;

class Solution {
public:
    unordered_set<int> table;

    bool findTarget(TreeNode* root, int k) {
        if (nullptr == root) {
            return false;
        }

        if (table.count(k - root->val)) {
            return true;
        }

        table.insert(root->val);

        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
// @lc code=end

