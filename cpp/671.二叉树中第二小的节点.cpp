/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
 *
 * https://leetcode.cn/problems/second-minimum-node-in-a-binary-tree/description/
 *
 * algorithms
 * Easy (48.06%)
 * Likes:    278
 * Dislikes: 0
 * Total Accepted:    65.9K
 * Total Submissions: 137.1K
 * Testcase Example:  '[2,2,5,null,null,5,7]'
 *
 * 给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或
 * 0。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。
 * 
 * 更正式地说，即 root.val = min(root.left.val, root.right.val) 总成立。
 * 
 * 给出这样的一个二叉树，你需要输出所有节点中的 第二小的值 。
 * 
 * 如果第二小的值不存在的话，输出 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [2,2,5,null,null,5,7]
 * 输出：5
 * 解释：最小的值是 2 ，第二小的值是 5 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [2,2,2]
 * 输出：-1
 * 解释：最小的值是 2, 但是不存在第二小的值。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [1, 25] 内
 * 1 <= Node.val <= 2^31 - 1
 * 对于树中每个节点 root.val == min(root.left.val, root.right.val)
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

// #include "include/TreeNode.h" // 提交注释, 本地调试使用

class Solution {
public:
    int res = -1;
    int findSecondMinimumValue(TreeNode* root) {
        if (nullptr == root) {
            return res;
        }

        traversal(root, root->val);
        
        return res;
    }

    void traversal(TreeNode* node, int rootVal) {
        if (nullptr == node) {
            return;
        }

        if (res != -1 && res < node->val) {
            return;
        }

        if (node->val > rootVal) {
            res = node->val;
        }

        traversal(node->left, rootVal);
        traversal(node->right, rootVal);
    }
};
// @lc code=end

