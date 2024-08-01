#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = -1, right = nums.size() - 1;

        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums.back())
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }

        int ans = nums[right];

        return ans;
    }
};