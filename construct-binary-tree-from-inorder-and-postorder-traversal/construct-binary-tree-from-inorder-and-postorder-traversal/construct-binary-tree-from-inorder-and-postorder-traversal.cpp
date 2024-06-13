#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//�ݹ�
class Solution {
    int post_idx;
    unordered_map<int, int> idx_map;
public:
    TreeNode* helper(int in_left, int in_right, vector<int>& inorder, vector<int>& postorder) {
        // �������û�нڵ㹹��������ˣ��ͽ���
        if (in_left > in_right) {
            return nullptr;
        }

        // ѡ�� post_idx λ�õ�Ԫ����Ϊ��ǰ�������ڵ�
        int root_val = postorder[post_idx];
        TreeNode* root = new TreeNode(root_val);

        // ���� root ����λ�÷ֳ�������������
        int index = idx_map[root_val];

        // �±��һ
        post_idx--;
        // ����������
        root->right = helper(index + 1, in_right, inorder, postorder);
        // ����������
        root->left = helper(in_left, index - 1, inorder, postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // �Ӻ�����������һ��Ԫ�ؿ�ʼ
        post_idx = (int)postorder.size() - 1;

        // ������Ԫ�أ��±꣩��ֵ�ԵĹ�ϣ��
        int idx = 0;
        for (auto& val : inorder) {
            idx_map[val] = idx++;
        }
        return helper(0, (int)inorder.size() - 1, inorder, postorder);
    }
};