#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int pre = -1546;
        int sign = 1;

        dfs(root, pre, sign);

        if (sign == -1)
            return false;
        else
            return true;

    }

    void dfs(TreeNode* node, int& pre ,int& sign)
    {
        if (node == nullptr)
        {
            return;
        }

        dfs(node->left, pre, sign);

        if (pre == -1546)
        {
            pre = node->val;
        }
        else
        {
            if (node->val <= pre)
            {
                sign = -1;
            }
            pre = node->val;
        }
        dfs(node->right, pre, sign);
    }
};