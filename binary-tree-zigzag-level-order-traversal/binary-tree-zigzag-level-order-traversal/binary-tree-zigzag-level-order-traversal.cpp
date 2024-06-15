#include <vector>
#include <queue>
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
    vector<vector<int>> ans;

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if (root == nullptr)
            return ans;

        queue<TreeNode*> Q;
        Q.push(root);
       

        while (!Q.empty())
        {
            int size = Q.size();
            vector<int> temp;


            while (size > 0)
            {
                TreeNode* node = Q.front();
                Q.pop();

                temp.emplace_back(node->val);

               
                if (node->left != nullptr) Q.push(node->left);
                if (node->right != nullptr) Q.push(node->right);

                size--;
            }

            if (ans.size() % 2) ranges::reverse(temp);
           
            ans.emplace_back(temp);
        }

        return ans;
    }
};