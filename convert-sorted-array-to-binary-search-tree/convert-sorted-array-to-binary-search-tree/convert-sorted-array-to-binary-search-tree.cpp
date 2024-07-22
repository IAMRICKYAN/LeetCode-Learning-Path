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
private:
    /**
     * �Է�Χ [left, right) ��Ԫ��������
     * ѡ������nums�и�����Χ�� [left, right) ���е���Ϊ���ڵ㣬[left, mid)��Ϊ��������[mid+1, right]��Ϊ������
     * @param nums: Ԫ������
     * @param left: ��߽�
     * @param right: �ұ߽�
     * @return: ����ĸ��ڵ�
    */
    TreeNode* buildTree(vector<int>& nums, int left, int right) {
        if (left >= right)return nullptr;            // ��ΧΪ�գ���û��Ԫ�ؿ��Թ���ڵ㣬���ؿ�
        int mid = left + ((right - left) >> 1);     // ��ȡ��Χ�е�
        TreeNode* node = new TreeNode(nums[mid], buildTree(nums, left, mid), buildTree(nums, mid + 1, right));  // �������ڵ㲢�ݹ���������
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size());     // ���������鷶Χ��Ԫ��������
    }
};