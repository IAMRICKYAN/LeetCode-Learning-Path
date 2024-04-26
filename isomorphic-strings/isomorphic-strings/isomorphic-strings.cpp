#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;

        int length = s.length();

        for (int i = 0; i < length; i++)
        {
            char x = s[i];
            char y = t[i];
            while ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x))
            {
                return false;
            }
            s2t[x] = y;
            t2s[y] = x;
        }

        return true;
    }
};