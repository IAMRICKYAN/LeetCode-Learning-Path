#include <vector>
#include <unordered_set>
#include <string>

using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st = { wordDict.begin(),wordDict.end() };
        vector<int> memo(n, -1);
        auto dfs = [&](auto&& dfs, int i) -> bool {
            if (i < 0) return true;
            if (memo[i] != -1) return memo[i];
            //枚举每一个切分点，不能为空
            bool ok = false;
            for (int k = i; k >= 0; k--) {
                string suffix = s.substr(k, i - k + 1);
                ok = ok || (st.contains(suffix) && dfs(dfs, k - 1));
                if (ok) return memo[i] = true;
            }
            return memo[i] = false;
            };
        return dfs(dfs, n - 1);
    }
};