#include <string>
#include <unordered_map>
#include <stack>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1)
        {
            return false;
        }

        unordered_map<char, char> pair = {
            {'}', '{'},
            {']', '['},
            {')', '('}
        };

        stack<char> stk;

        for (auto& S : s)
        {
            if (pair.count(S))
            {
                if (stk.empty() || pair[S] != stk.top())
                    return false;

                stk.pop();
            }
            else
            {
                stk.push(S);
            }
        }

        return stk.empty();
    }
};