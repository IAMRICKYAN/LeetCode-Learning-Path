#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> path(n), on_path(n);


        function<void(int)>  dfs = [&](int i)
            {
                if (i == n)
                {
                    ans.emplace_back(path);
                    return;
                }

                for (int j = 0; j < n; j++)
                {
                    if (!on_path[j])
                    {
                        path[i] = nums[j];
                        on_path[j] = true;

                        dfs(i + 1);
                        on_path[j] = false;
                    }
                }
            };

        dfs(0);

        return ans;
    }
};