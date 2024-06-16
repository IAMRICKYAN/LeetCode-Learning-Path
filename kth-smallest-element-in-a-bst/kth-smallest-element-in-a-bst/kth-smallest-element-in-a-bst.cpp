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
    int res;
    int K;


    int kthSmallest(TreeNode* root, int k) {
        
        this->K = k;
        res = 1;
        dfs(root);

        return res;
    }

    void dfs(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        dfs(root->left);

        if (K == 0) return;
        if (--K == 0) res = root->val;

        dfs(root->right);
    }
   
};