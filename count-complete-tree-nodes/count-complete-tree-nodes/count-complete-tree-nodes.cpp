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
    // ������������
    int countLevels(TreeNode* root) {
        int levels = 0;
        while (root) {
            root = root->left; levels += 1;
        }
        return levels;
    }

    /*
    * ���ܣ� �ж����һ���index�������Ƿ����
    * root�� ���������ڵ�
    * index���ж����һ������Ϊindex�Ľڵ��Ƿ����, ������Χ��[1, 2^depth]
    * depth�������ڶ�������, ������Ϊ�����������һ��Ľڵ������� 2^depth
    */
    bool is_exist(TreeNode* root, int index, int depth) {
        TreeNode* node = root;
        while (depth) {
            // ���һ��ֽ���
            int mid = ((1 << depth) >> 1);
            if (index > mid) {
                // ���������������Ҫ��������ֵ
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
        // 3. ���ֲ���
        if (root == nullptr) return 0;
        // ���������
        int depth = countLevels(root);
        // �����ڶ������
        int depth_prev = depth - 1;

        int start = 1, end = (1 << depth_prev), mid = 0;
        while (start <= end) {
            mid = start + ((end - start) >> 1);
            if (is_exist(root, mid, depth_prev)) start = mid + 1;
            else end = mid - 1;
        }
        // start - 1Ϊ���һ��ڵ���
        int ret = (1 << depth_prev) - 1 + start - 1;
        return ret;
    }
};