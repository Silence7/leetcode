/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 *
 * https://leetcode.cn/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (47.59%)
 * Likes:    851
 * Dislikes: 0
 * Total Accepted:    153.7K
 * Total Submissions: 323K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 * 
 * 
 * 给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true
 * ；否则，返回 false 。
 * 
 * 二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,4,5,1,2], subRoot = [4,1,2]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * root 树上的节点数量范围是 [1, 2000]
 * subRoot 树上的节点数量范围是 [1, 1000]
 * -10^4 
 * -10^4 
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

class Solution {
public:

    bool check(TreeNode* node, TreeNode* subNode) {
        if (nullptr == node && nullptr == subNode) {
            return true;
        }

        if ((nullptr != node && nullptr == subNode) || (nullptr == node && nullptr != subNode) || (node->val != subNode->val)) {
            return false;
        }

        return check(node->left, subNode->left) && check(node->right, subNode->right);
    }

    bool dfs(TreeNode* node, TreeNode* subNode) {
        if (nullptr == node) {
            return false;
        }

        return check(node, subNode) || dfs(node->left, subNode) || dfs(node->right, subNode);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
};
// @lc code=end

