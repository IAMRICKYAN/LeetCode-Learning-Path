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

            if (res != -1) //֮ǰ�����
            {
                return res;
            }

            if (c < coins[i])
            {
                return res = dfs(dfs, i - 1, c);
            }

            //�ݹ鿼�������������ʹ�õ�ǰӲ�Һ�����ʹ��һ����ǰӲ�ҡ�ȡ�������������Сֵ�����洢�� memo[i][c] �С�
            return res = min(dfs(dfs, i - 1, c), dfs(dfs, i, c - coins[i]) + 1);

            };

        int ans = dfs(dfs, n - 1, amount);
        return ans < INT_MAX / 2 ? ans : -1;

    }
             
};