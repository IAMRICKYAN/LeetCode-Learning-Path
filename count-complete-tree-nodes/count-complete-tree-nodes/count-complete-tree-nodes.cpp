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

class Solution {
public:
    // 求二叉树的深度
    int countLevels(TreeNode* root) {
        int levels = 0;
        while (root) {
            root = root->left; levels += 1;
        }
        return levels;
    }

    /*
    * 功能： 判断最后一层第index个索引是否存在
    * root： 二叉树根节点
    * index：判断最后一层索引为index的节点是否存在, 索引范围是[1, 2^depth]
    * depth：倒数第二层的深度, 这是因为满二叉树最后一层的节点数等于 2^depth
    */
    bool is_exist(TreeNode* root, int index, int depth) {
        TreeNode* node = root;
        while (depth) {
            // 最后一层分界线
            int mid = ((1 << depth) >> 1);
            if (index > mid) {
                // 如果在右子树，需要更新索引值
                index -= mid;
                node = node->right;
            }
            else {
                node = node->left;
            }
            depth -= 1;
        }
        return node != nullptr;
    }

    int countNodes(TreeNode* root) {
        // 3. 二分查找
        if (root == nullptr) return 0;
        // 二叉树深度
        int depth = countLevels(root);
        // 倒数第二层深度
        int depth_prev = depth - 1;

        int start = 1, end = (1 << depth_prev), mid = 0;
        while (start <= end) {
            mid = start + ((end - start) >> 1);
            if (is_exist(root, mid, depth_prev)) start = mid + 1;
            else end = mid - 1;
        }
        // start - 1为最后一层节点数
        int ret = (1 << depth_prev) - 1 + start - 1;
        return ret;
    }
};