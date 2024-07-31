#include <vector>

using namespace std;

class Solution {
public:

    // 开区间写法
    int lower_bound3(vector<int>& nums, int target) {
        int left = -1, right = nums.size(); // 开区间 (left, right)
        while (left + 1 < right) { // 区间不为空
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
            // 也可以这样写
            // (nums[mid] < target ? left : right) = mid;
        }
        return right;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound3(nums, target); // 使用其中一种写法即可
        if (start == nums.size() || nums[start] != target) {
            return { -1, -1 }; // nums 中没有 target
        }
        // 如果 start 存在，那么 end 必定存在
        int end = lower_bound3(nums, target + 1) - 1;
        return { start, end };
    }

    
};