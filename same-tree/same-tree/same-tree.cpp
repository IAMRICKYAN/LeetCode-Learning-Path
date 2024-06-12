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

//广度优先搜索
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr && q != nullptr) return false;
        if (p != nullptr && q == nullptr) return false;

        queue<TreeNode*> Q1, Q2;

        Q1.push(p);
        Q2.push(q);

        while (!Q1.empty() && !Q2.empty())
        {
            int size_Q1 = Q1.size();
            int size_Q2 = Q2.size();

            while (size_Q1 > 0 && size_Q2>0)
            {
                TreeNode* node1 = Q1.front(); Q1.pop();
                TreeNode* node2 = Q2.front(); Q2.pop();

                if (node1->val != node2->val)
                {
                    return false;
                }

                if (node1->left != nullptr) Q1.push(node1->left);
                if (node1->right != nullptr) Q1.push(node1->right);

                if (node2->left != nullptr) Q2.push(node2->left);
                if (node2->right != nullptr) Q2.push(node2->right);

                if (node1->left != nullptr && node2->left == nullptr) return false;
                if (node1->left == nullptr && node2->left != nullptr) return false;

                if (node1->right != nullptr && node2->right == nullptr) return false;
                if (node1->right == nullptr && node2->right != nullptr) return false;

                size_Q1--;
                size_Q2--;
            }
        }

        if (Q1.empty() && Q2.empty())
            return true;

        return false;
    }
};


//深度优先搜索
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else
        {
            if (p == nullptr || q == nullptr)
            {
                return false;
            }
            else
            {
                if (p->val != q->val)
                {
                    return false;
                }
                else
                {
                    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
                }
            }
        }
    }
};