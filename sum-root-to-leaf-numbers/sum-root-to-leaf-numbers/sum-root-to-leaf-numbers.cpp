
#include <iostream>
#include <vector>

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
    int sumNumbers(TreeNode* root) {

        int sum = 0;
        vector<int> num;
        auto ans = calculate(root,sum,num);
        
        int size = ans.size();
        int Allsum = 0;

        for (auto& a : ans)
        {
            Allsum += a;
        }

        return Allsum;
    }

    vector<int> calculate(TreeNode* root, int sum,vector<int> num)
    {
        if (root == nullptr)
        {
            return num;
        }

        sum = sum * 10 + root->val;

        if (root->left == root->right)
        {
            num.emplace_back(sum);
        }

        num = calculate(root->left, sum, num);
        num = calculate(root->right, sum, num);

        return num;
    }
};