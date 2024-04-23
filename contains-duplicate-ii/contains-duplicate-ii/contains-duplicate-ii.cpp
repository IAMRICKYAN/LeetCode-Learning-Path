#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int num_size = nums.size();
        unordered_map<int,bool> set;
        for (int i = 0; i < num_size; i++)
        {
            if (i > k) set[nums[i - k -1]] = false;
            if (set[nums[i]]) return true;
            set[nums[i]] = true;
        }

        return false;
    }
};