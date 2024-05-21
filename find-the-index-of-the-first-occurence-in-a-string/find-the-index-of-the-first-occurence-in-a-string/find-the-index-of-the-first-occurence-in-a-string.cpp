#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int m = haystack.size();
        int n = needle.size();

        if (n == 0) return 0;

        haystack.insert(haystack.begin(), ' ');
        needle.insert(needle.begin(), ' ');


        vector<int> next(n + 1);

        for (int i = 2, j = 0; i < n; i++)
        {
            while (j && needle[i] != needle[j + 1])
            {
                j = next[j];
            }

            if (needle[i] == needle[j + 1])
            {
                j++;
            }

            next[i] = j;
        }

        for (int i = 1, j = 0; i < m ; i++)
        {
            while (j && haystack[i] != needle[j + 1])
            {
                j = next[j];
            }

            if (haystack[i] == needle[j + 1])
            {
                j++;
            }

            if (j == n) return i - n;

        }

        return -1;
    }
};