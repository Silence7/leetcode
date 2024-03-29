/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 *
 * https://leetcode.cn/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Medium (60.34%)
 * Likes:    812
 * Dislikes: 0
 * Total Accepted:    122.6K
 * Total Submissions: 203.1K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * 给你二叉搜索树的根节点 root ，该树中的 恰好 两个节点的值被错误地交换。请在不改变其结构的情况下，恢复这棵树 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,3,null,null,2]
 * 输出：[3,1,null,null,2]
 * 解释：3 不能是 1 的左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [3,1,4,null,null,2]
 * 输出：[2,1,4,null,null,3]
 * 解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树上节点的数目在范围 [2, 1000] 内
 * -2^31 <= Node.val <= 2^31 - 1
 * 
 * 
 * 
 * 
 * 进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用 O(1) 空间的解决方案吗？
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
    TreeNode* pre;
    TreeNode* first;
    TreeNode* second;
    void recoverTree(TreeNode* root) {
        
        traversal(root);

        if (nullptr != first && nullptr != second) {
            // std::swap(first, second);
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
    }

    void traversal(TreeNode* node) {
        if (nullptr == node) {
            return;
        }

        traversal(node->left);
        
        if (nullptr == pre) {
            pre = node;
        } else {
            if (pre->val > node->val) {
                if (nullptr == first) {
                    first = pre;
                }
                
                second = node;
            }

            pre = node;
        }

        traversal(node->right);
    }
};
// @lc code=end

