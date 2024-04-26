#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;


//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        int numcount = nums.size();
//        int tag = 0;
//        sort(nums.begin(),nums.end());
//        for (auto& i : nums)
//        {
//            if (i == tag)
//                tag++;
//            else
//                return tag;
//        }
//        
//        return tag;
//    }
//};

//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        unordered_set<int> findmissing;
//
//        int numsize = nums.size();
//
//        for (auto& i : nums)
//        {
//            findmissing.insert(i);
//        }
//
//        int missing = -1;
//
//        for (int i = 0; i < numsize; i++)
//        {
//            if (!findmissing.count(i))
//            {
//                missing = i;
//                break;
//            }
//            
//        }
//        if (missing == -1)
//            return numsize;
//        return missing;
//    }
//};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            res ^= nums[i];
        }
        for (int i = 0; i <= n; i++) {
            res ^= i;
        }
        return res;
    }
};

