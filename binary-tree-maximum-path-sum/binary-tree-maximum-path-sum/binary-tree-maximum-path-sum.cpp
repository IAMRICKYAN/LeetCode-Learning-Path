#include <iostream>
#include <functional>

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
    int maxPathSum(TreeNode* root) {

        int ans = INT_MIN;

        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (node == nullptr)
                return 0;

            int left_val = dfs(node->left);
            int right_val = dfs(node->right);
            ans = max(ans, left_val + right_val + node->val);

            return max(max(left_val, right_val) + node->val, 0); //返回以当前节点为终点的最大路径和
            };

        dfs(root);

        return ans;
    }
};