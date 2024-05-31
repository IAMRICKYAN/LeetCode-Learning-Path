#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i = 0;
        int n = nums.size();

        while (i < n) {
            int low = i;
            i++;

            while (i < n && nums[i] == nums[i - 1] + 1) {
                i++;
            }

            int high = i - 1;

            if (low < high) {
                ans.push_back(to_string(nums[low]) + "->" + to_string(nums[high]));
            }
            else {
                ans.push_back(to_string(nums[low]));
            }
        }

        return ans;
    }
};