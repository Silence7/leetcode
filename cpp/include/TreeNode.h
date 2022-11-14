#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using std::vector;
using std::stack;
using std::queue;
using std::reverse;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif

// 递归前中后序
void recursionTraversal(TreeNode* root) {
    if (nullptr == root) {
        return;
    }

    // 前序
    // root->val;

    recursionTraversal(root->left);

    // 中序
    // root->val;

    recursionTraversal(root->right);

    // 后序
    // root->val;
}

// 迭代前序
void preOrderIterationTraversal(TreeNode* root) {
    if (nullptr == root) {
        return;
    }

    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
        TreeNode* cur = stk.top(); stk.pop();
        if (nullptr != cur) {
            cur->val;
        }

        if (nullptr != cur->right)  {
            stk.push(cur->right);
        }

        if (nullptr != cur->left) {
            stk.push(cur->left);
        }
    }
}

// 迭代中序
void inOrderIterationTraversal(TreeNode* root) {
    if (nullptr == root) {
        return;
    }

    TreeNode* cur = root;
    stack<TreeNode*> stk;

    while (nullptr != cur || !stk.empty()) {
        if (nullptr != cur) {
            stk.push(cur);

            cur = cur->left;
        } else {
            TreeNode* cur = stk.top(); stk.pop();
            
            // 中序
            // cur->val;

            cur = cur->right;
        }
    }
}

// 迭代后序
void postOrderIterationTraversal(TreeNode* root) {
    if (nullptr == root) {
        return;
    }

    vector<TreeNode*> vec;
    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
        TreeNode* cur = stk.top(); stk.pop();
        if (nullptr != cur) {
            vec.push_back(cur);
        }

        if (nullptr != cur->left) {
            stk.push(cur->left);
        }

        if (nullptr != cur->right) {
            stk.push(cur->right);
        }
    }
    
    //  中右左 反序 左右中
    reverse(vec.begin(), vec.end());
}

// 迭代前中后统一模板
void iterationTraversal(TreeNode* root) {
    if (nullptr == root) {
        return;
    }

    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
        TreeNode* cur = stk.top(); stk.pop();
        if (nullptr != cur) {
              // 所有节点入栈, 前中后顺序不一样

            // 右
            if (nullptr != cur->right) {
                stk.push(cur->right);
            }

            // 左
            if (nullptr != cur->left) {
                stk.push(cur->left);
            }

            // 中
            stk.push(cur);
            stk.push(nullptr);

        } else {
            TreeNode* cur = stk.top(); stk.pop();

            // 处理节点
            // cur->val
        }
    }
}

// 层序遍历，广度优先算法
void levelOrderRecursion(TreeNode* node, vector<vector<int>>& vec, int depth) {
    if (nullptr == node) {
        return;
    }

    if (vec.size() == depth) {
        vec.push_back(vector<int>());
    }

    vec[depth].push_back(node->val);

    levelOrderRecursion(node->left, vec, depth + 1);
    levelOrderRecursion(node->right, vec, depth + 1);
}

void levelOrderIteration(TreeNode* root) {
    if (nullptr != root) {
        return;
    }

    vector<vector<int>> res;
    queue<TreeNode*> que;
    que.push(root);

    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;

        for (int i = 0; i < size; i++) {
            TreeNode* cur = que.front(); que.pop();
            vec.push_back(cur->val);

            if (nullptr != cur->left) {
                que.push(cur->left);
            }

            if (nullptr != cur->right) {
                que.push(cur->right);
            }
        }

        res.push_back(vec);
    }
}
