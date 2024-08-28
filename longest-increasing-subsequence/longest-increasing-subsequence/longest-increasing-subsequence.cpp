#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> memo(n);

        auto dfs = [&](auto&& dfs, int i) -> int {

            int& res = memo[i];

            if (res > 0)
            {
                return res;
            }

            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    res = max(res, dfs(dfs, j));
                }


            }

            return ++res;

         };


        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dfs(dfs, i));
        }

        return ans;
    }
};