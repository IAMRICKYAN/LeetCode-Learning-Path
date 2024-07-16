#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

class Solution {

string MAPPING[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

public:
    vector<string> letterCombinations(string digits) {

        int n = digits.size();
        if (n == 0) return {};

        vector<string> ans;

        string str(n, 0);

        function<void(int)> dfs = [&](int i)
        {
                if (i == n)
                {
                    ans.emplace_back(str);
                    return;
                }

                for (char c : MAPPING[digits[i] - '0'])
                {
                    str[i] = c;
                    dfs(i + 1);
                }
        };

        dfs(0);

        return ans;
      
    }
};