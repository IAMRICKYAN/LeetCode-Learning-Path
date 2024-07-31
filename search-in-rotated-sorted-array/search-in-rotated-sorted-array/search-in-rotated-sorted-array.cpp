#include <vector>
using namespace std;

class Solution {
    // 153. Ѱ����ת���������е���Сֵ
    int findMin(vector<int>& nums) {
        int left = -1, right = nums.size() - 1; // ������ (-1, n-1)
        while (left + 1 < right) { // �����䲻Ϊ��
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums.back()) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return right;
    }

    // ������������ target ���±�
    int lower_bound(vector<int>& nums, int left, int right, int target) {
        while (left + 1 < right) { // �����䲻Ϊ��
            // ѭ����������
            // nums[left] < target
            // nums[right] >= target
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid; // ��Χ��С�� (mid, right)
            }
            else {
                right = mid; // ��Χ��С�� (left, mid)
            }
        }
        return nums[right] == target ? right : -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int i = findMin(nums);
        if (target > nums.back()) { // target �ڵ�һ��
            return lower_bound(nums, -1, i, target); // ������ (-1, i)
        }
        // target �ڵڶ���
        return lower_bound(nums, i - 1, nums.size(), target); // ������ (i-1, n)
    }
};