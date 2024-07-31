#include <vector>
using namespace std;

class Solution {
    // 153. 寻找旋转排序数组中的最小值
    int findMin(vector<int>& nums) {
        int left = -1, right = nums.size() - 1; // 开区间 (-1, n-1)
        while (left + 1 < right) { // 开区间不为空
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

    // 有序数组中找 target 的下标
    int lower_bound(vector<int>& nums, int left, int right, int target) {
        while (left + 1 < right) { // 开区间不为空
            // 循环不变量：
            // nums[left] < target
            // nums[right] >= target
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid; // 范围缩小到 (mid, right)
            }
            else {
                right = mid; // 范围缩小到 (left, mid)
            }
        }
        return nums[right] == target ? right : -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int i = findMin(nums);
        if (target > nums.back()) { // target 在第一段
            return lower_bound(nums, -1, i, target); // 开区间 (-1, i)
        }
        // target 在第二段
        return lower_bound(nums, i - 1, nums.size(), target); // 开区间 (i-1, n)
    }
};