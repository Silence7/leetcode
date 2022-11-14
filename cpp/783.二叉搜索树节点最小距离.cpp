/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
 *
 * https://leetcode.cn/problems/minimum-distance-between-bst-nodes/description/
 *
 * algorithms
 * Easy (59.98%)
 * Likes:    238
 * Dislikes: 0
 * Total Accepted:    81.5K
 * Total Submissions: 135.9K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
 * 
 * 差值是一个正数，其数值等于两值之差的绝对值。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [4,2,6,1,3]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,0,48,null,null,12,49]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目范围是 [2, 100]
 * 0 <= Node.val <= 10^5
 * 
 * 
 * 
 * 
 * 注意：本题与
 * 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/
 * 相同
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

#include <climits>
#include <algorithm>
using std::min;
using std::abs;

class Solution {
public:
    int res = INT_MAX;
    int pre = INT_MAX;

    int minDiffInBST(TreeNode* root) {
        // return recursionTraversal(root);
        return iterationTraversal(root);
    }

    // 递归
    int recursionTraversal(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        recursionTraversal(root->left);

        res = min(res, abs(root->val - pre));
        pre = root->val;
        
        recursionTraversal(root->right);
        
        return res;
    }

    // 迭代, 中序，非统一写法
    int iterationTraversal(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        stack<TreeNode*> stk;
        // stk.push(root);
        TreeNode* iter = root;

        while (nullptr != iter || !stk.empty()) {
            if (nullptr != iter) {
                stk.push(iter);
                iter = iter->left;
            } else {
                iter = stk.top(); stk.pop();

                res = min(res, abs(iter->val - pre));
                pre = iter->val;
                
                iter = iter->right;
            }
        }

        return res;
    }
};
// @lc code=end

