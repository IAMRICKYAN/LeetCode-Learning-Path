#include <iostream>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//深度优先搜索
class Solution {
public:
    int maxDepth(TreeNode* root) {

        if (root == nullptr)
            return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;

    }
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> Q;

        if (root == nullptr) return 0;

        Q.push(root);

        int ans = 0;
        
        while (!Q.empty())
        {
            int size = Q.size();

            while (size > 0)
            {
                TreeNode* node = Q.front();
                Q.pop();

                if (node->left != nullptr) Q.push(node->left);
                if (node->right != nullptr) Q.push(node->right);

                size--;
            } 

            ans += 1;
        }

        return ans;
    }
};