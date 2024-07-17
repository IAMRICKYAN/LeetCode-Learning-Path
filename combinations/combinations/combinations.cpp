#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> ans;
        vector<int> path;

        function<void(int)> dfs = [&](int i)
            {
                int d = k - path.size();
                if (d == 0)
                {
                    ans.emplace_back(path);
                    return;
                }

                for (int j = i; j >= d; j--)
                {
                    path.emplace_back(j);
                    dfs(j - 1);
                    path.pop_back();
                }

            };

        dfs(n);

        return ans;
    }
};