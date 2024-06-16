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
    int getMinimumDifference(TreeNode* root) {

    }
};

class Solution {
public:

    void dfs(TreeNode* root, int& pre, int& ans)
    {
        if (root == nullptr)
        {
            return;
        }

        dfs(root->right, pre, ans);
        if (pre == -1)
        {
            pre = root->val;
        }
        else
        {
            ans = min(ans, pre - root->val);
            pre = root->val;
        }

        dfs(root->left, pre, ans);


    }


    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        int pre = -1;

        dfs(root, pre, ans);

        return ans;

    }
};