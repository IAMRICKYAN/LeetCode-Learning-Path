#include <iostream>
#include <vector>

using namespace std;

//nums = [1, 1, 2]

//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//
//        int n = nums.size();
//        int fast = 1, slow = 1;
//        while (fast < n) {
//            if (nums[fast] != nums[fast - 1]) {
//                nums[slow] = nums[fast];
//                ++slow;
//            }
//            ++fast;
//        }
//        return slow;
//
//    }
//};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 1, right = 1;
        int n = nums.size();
        while (right < n)
        {
            if (nums[right] != nums[right-1])
            {
                nums[left] = nums[right];
                left++;
            }
            right++;
        }
        return left;
    }
};