#include <vector>
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

class Solution {
public:

    vector<double> ans;

    vector<double> averageOfLevels(TreeNode* root) {

        queue<TreeNode*> Q;
        Q.push(root);

        while (!Q.empty())
        {
            double sum = 0;
            int size = Q.size();
            int s = size;
            while (size > 0)
            {

                TreeNode* temp = Q.front();
                Q.pop();
                sum += temp->val;

                if (temp->left != nullptr) Q.push(temp->left);
                if (temp->right != nullptr) Q.push(temp->right);

                size--;

            }

            ans.emplace_back(sum / s);

        }

        return ans;

    }
};