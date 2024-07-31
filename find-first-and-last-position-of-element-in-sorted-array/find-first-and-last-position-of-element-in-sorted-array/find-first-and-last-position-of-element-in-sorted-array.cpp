#include <vector>

using namespace std;

class Solution {
public:

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
            // Ҳ��������д
            // (nums[mid] < target ? left : right) = mid;
        }
        return right;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound3(nums, target); // ʹ������һ��д������
        if (start == nums.size() || nums[start] != target) {
            return { -1, -1 }; // nums ��û�� target
        }
        // ��� start ���ڣ���ô end �ض�����
        int end = lower_bound3(nums, target + 1) - 1;
        return { start, end };
    }

    
};