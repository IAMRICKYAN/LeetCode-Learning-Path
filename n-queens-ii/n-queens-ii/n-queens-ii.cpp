#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<int> on_path(n), diag1(n * 2 - 1), diag2(n * 2 - 1);
        function<void(int)> dfs = [&](int r)
            {
                if (r == n)
                {
                    ans++;
                    return;
                }

                for (int c = 0; c < n; c++)
                {
                    int rc = r - c + n - 1;
                    if (!on_path[c] && !diag1[r + c] && !diag2[rc]) {
                        on_path[c] = diag1[r + c] = diag2[rc] = true;
                        dfs(r + 1);
                        on_path[c] = diag1[r + c] = diag2[rc] = false; // »Ö¸´ÏÖ³¡
                    }
                }
            };

        dfs(0);

        return ans;
    }
};