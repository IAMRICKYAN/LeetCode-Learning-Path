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
     * 对范围 [left, right) 的元素生成树
     * 选择数组nums中给定范围的 [left, right) 的中点作为根节点，[left, mid)作为左子树，[mid+1, right]作为右子树
     * @param nums: 元素数组
     * @param left: 左边界
     * @param right: 右边界
     * @return: 构造的根节点
    */
    TreeNode* buildTree(vector<int>& nums, int left, int right) {
        if (left >= right)return nullptr;            // 范围为空，即没有元素可以构造节点，返回空
        int mid = left + ((right - left) >> 1);     // 获取范围中点
        TreeNode* node = new TreeNode(nums[mid], buildTree(nums, left, mid), buildTree(nums, mid + 1, right));  // 创建根节点并递归生成子树
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size());     // 对整个数组范围的元素生成树
    }
};