#include <vector>
#include <string>
#include <functional>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int m = n * 2;
        vector<string> ans;
        string path(m, 0);
        function<void(int, int)> dfs = [&](int i, int open) {
            if (i == m) {
                ans.emplace_back(path);
                return;
            }
            if (open < n) { // ¿ÉÒÔÌî×óÀ¨ºÅ
                path[i] = '(';
                dfs(i + 1, open + 1);
            }
            if (i - open < open) { // ¿ÉÒÔÌîÓÒÀ¨ºÅ
                path[i] = ')';
                dfs(i + 1, open);
            }
            };
        dfs(0, 0);
        return ans;
    }
};