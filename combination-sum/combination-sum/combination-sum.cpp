#include <vector>
#include <functional>
#include <ranges>
#include <algorithm>

using namespace std;

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {

        std::ranges::sort(candidates);

        std::vector<std::vector<int>> ans;
        std::vector<int> path;

        function<void(int, int)> dfs = [&](int i, int left)
            {
                if (left == 0)
                {
                    ans.emplace_back(path);
                    return;
                }

                if (left < candidates[i])
                {
                    return;
                }

                for (int j = i; j < candidates.size(); j++)
                {
                    path.push_back(candidates[j]);
                    dfs(j, left - candidates[j]);
                    path.pop_back();
                }
            };

        dfs(0, target);

        return ans;


    }
};