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
    bool isSymmetric(TreeNode* root) {

        return check(root, root);
 

    }

    bool check(TreeNode* p, TreeNode* q)
    {
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
                return (p->val == q->val) && (check(p->left, q->right)) && (check(p->right, q->left));
            }
        }

    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }

    bool check(TreeNode* u, TreeNode* v)
    {
        queue<TreeNode*> q;
        q.push(u);
        q.push(v);

        while (!q.empty())
        {
            u = q.front(); q.pop();
            v = q.front(); q.pop();

            if (!u && !v) continue;
            if ((!u || !v) || (u->val != v->val)) return false;

            q.push(u->left);
            q.push(v->right);

            q.push(u->right);
            q.push(v->left);
        }
        return true;
    } 
};