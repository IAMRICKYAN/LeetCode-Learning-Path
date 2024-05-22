#include <iostream>
#include <string>
#include <vector>

using namespace std;


//双指针
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int str_first = 0;
        int str_second = 0;

        if (s == "")

        {
            return true;
        }

        int t_size = t.length();
        int s_size = s.length();

        while (str_second < t_size)
        {

            if (s[str_first] == t[str_second])
            {
                str_first++;
                if (str_first == s_size)
                    return true;
            }

            str_second++;
        }

        return false;


    }
};

//动态规划
class Solution {
public:
    bool isSubsequence(string s, string t) {
        t.insert(t.begin(), ' ');
        int len1 = s.size();
        int len2 = t.size();

        vector<vector<int>> dp(len2, vector<int>(26, 0));

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            int nextPos = -1; //表示接下来不会出现该字符

            for (int i = len2 - 1; i >= 0; i--)
            {
                dp[i][ch - 'a'] = nextPos;
                if (t[i] == ch)
                    nextPos = i;
            }
        }

        int index = 0;
        for (char c : s)
        {
            index = dp[index][c - 'a'];
            if (index == -1)
                return false;
        }

        return true;
    }

};