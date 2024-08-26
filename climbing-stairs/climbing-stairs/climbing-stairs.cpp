#include <vector>

using namespace std;

class Solution {
public:

    vector<int> b;

    int dfs(int n)
    {
        if (n <= 1)
        {
            return 1;
        }

        int& res = b[n];

        if (res)
        {
            return res;
        }

        return res = dfs(n - 2) + dfs(n - 1);
    }

    int climbStairs(int n) {

        b.resize(n + 1);

        return dfs(n);

    }
};


class Solution {
public:
    int climbStairs(int n) {
        vector<int> f(n + 1);
        f[0] = f[1] = 1;
        for (int i = 2; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};