#include <iostream>
#include <vector>


using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> l;
        preorderTraversal(root, l);
        int n = l.size();
        for (int i = 1; i < n; i++) {
            TreeNode* prev = l.at(i - 1), * curr = l.at(i);
            prev->left = nullptr;
            prev->right = curr;
        }
    }

    void preorderTraversal(TreeNode* root, vector<TreeNode*>& l) {
        if (root != NULL) {
            l.push_back(root);
            preorderTraversal(root->left, l);
            preorderTraversal(root->right, l);
        }
    }
};

class Solution {
public:
    void flatten(TreeNode* root) {

        TreeNode* cur = root;
        while (cur != nullptr)
        {
            if (cur->left != nullptr)
            {
                TreeNode* next = cur->left;
                TreeNode* predecessor = next;

                while (predecessor->right != nullptr)
                {
                    predecessor = predecessor->right;
                }

                predecessor->right = cur->right;
                cur->left = nullptr;
                cur->right = next;
            }

            cur = cur->right;
        }

    }

};