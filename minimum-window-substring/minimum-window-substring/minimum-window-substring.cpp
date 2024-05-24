#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        string ans;

        if (n < m)
        {
            return "";
        }

        unordered_map<char, int> t_num,s_num;
        for (auto word : t)
        {
            t_num[word]++;
        }

        int pos = 0, minlen = INT_MAX;
        int left = 0, right = 0;
        int count = 0;

        while (right < n)
        {
            char in = s[right++];
            if (++s_num[in] <= t_num[in])
            {
                ++count;
            }

            while (count == m)
            {
                if (right - left < minlen)
                {
                    pos = left;
                    minlen = right - left;

                }

                char out = s[left++];
                if (s_num[out]-- <= t_num[out])
                {
                    --count;
                }
            }

        }

        return minlen == INT_MAX ? "" : s.substr(pos, minlen);
    }
};