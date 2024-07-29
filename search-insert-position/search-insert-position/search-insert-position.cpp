#include <vector>

using namespace std;

class Solution {
    // lower_bound ������С������ nums[i] >= target �� i
    // �������Ϊ�գ������������� < target���򷵻� nums.size()
    // Ҫ�� nums �Ƿǵݼ��ģ��� nums[i] <= nums[i + 1]

    // ������д��
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size() - 1; // ������ [left, right]
        while (left <= right) { // ���䲻Ϊ��
            // ѭ����������
            // nums[left-1] < target
            // nums[right+1] >= target
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1; // ��Χ��С�� [mid+1, right]
            }
            else {
                right = mid - 1; // ��Χ��С�� [left, mid-1]
            }
        }
        return left;
    }

    // ����ҿ�����д��
    int lower_bound2(vector<int>& nums, int target) {
        int left = 0, right = nums.size(); // ����ҿ����� [left, right)
        while (left < right) { // ���䲻Ϊ��
            // ѭ����������
            // nums[left-1] < target
            // nums[right] >= target
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1; // ��Χ��С�� [mid+1, right)
            }
            else {
                right = mid; // ��Χ��С�� [left, mid)
            }
        }
        return left;
    }

    // ������д��
    int lower_bound3(vector<int>& nums, int target) {
        int left = -1, right = nums.size(); // ������ (left, right)
        while (left + 1 < right) { // ���䲻Ϊ��
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
        return right;
    }

public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound3(nums, target); // ѡ������һ��д������
    }
};