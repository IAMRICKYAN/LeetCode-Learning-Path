#include <iostream>
#include <vector>
#include <unordered_map>
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        vector<int> index(n + 1);
        for (int i = 0; i < n; i++) {
            index[postorder[i]] = i;
        }

        function<TreeNode* (int, int, int, int)> dfs = [&](int pre_l, int pre_r, int post_l, int post_r) -> TreeNode* {
            if (pre_l == pre_r) { // 空节点
                return nullptr;
            }
            if (pre_l + 1 == pre_r) { // 叶子节点
                return new TreeNode(preorder[pre_l]);
            }
            int left_size = index[preorder[pre_l + 1]] - post_l + 1; // 左子树的大小
            TreeNode* left = dfs(pre_l + 1, pre_l + 1 + left_size, post_l, post_l + left_size);
            TreeNode* right = dfs(pre_l + 1 + left_size, pre_r, post_l + left_size, post_r - 1);
            return new TreeNode(preorder[pre_l], left, right);
            };
        return dfs(0, n, 0, n); // 左闭右开区间
    }
};