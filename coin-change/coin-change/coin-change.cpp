#include <vector>

using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> memo(n, vector<int>(amount + 1, -1));

        auto dfs = [&](auto&& dfs, int i, int c) -> int {
            if (i < 0)
            {
                return c == 0 ? 0 : INT_MAX / 2;
            }

            int& res = memo[i][c];

            if (res != -1) //之前计算过
            {
                return res;
            }

            if (c < coins[i])
            {
                return res = dfs(dfs, i - 1, c);
            }

            //递归考虑两种情况：不使用当前硬币和至少使用一个当前硬币。取这两种情况的最小值，并存储在 memo[i][c] 中。
            return res = min(dfs(dfs, i - 1, c), dfs(dfs, i, c - coins[i]) + 1);

            };

        int ans = dfs(dfs, n - 1, amount);
        return ans < INT_MAX / 2 ? ans : -1;

    }
             
};