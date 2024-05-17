#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<char> str;
        int string_size = s.size();

        for (int i = string_size - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (!str.empty()) {
                    return str.size();
                }
            }
            else {
                str.push_back(s[i]);
            }
        }

        return str.size();
    }
};