#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty())
            return ans;

        int n = s.length(), m = words.size(), w = words[0].length();

        unordered_map<string, int> total;

        for (int i = 0; i < words.size(); i++)
        {
            total[words[i]]++;
        }

        for (int i = 0; i < w; i++)
        {
            unordered_map<string, int> window;
            int cnt = 0;

            for (int j = i; j + w <= n; j += w)
            {
                if (j - i >= m * w) 
                {
                    string word = s.substr(j - m * w, w);
                    window[word]--;
                    if (window[word] < total[word])
                    {
                        cnt--;
                    }
                }

                string word = s.substr(j, w);
                window[word]++;
                if (window[word] <= total[word])
                {
                    cnt++;
                }

                if (cnt == m)
                {
                    ans.push_back(j - (m - 1) * w);
                }
            }
        }
        return ans;
    }
};