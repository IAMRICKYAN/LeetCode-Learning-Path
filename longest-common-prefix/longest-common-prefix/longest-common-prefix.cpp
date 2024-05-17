#include <iostream>
#include <vector>
#include <string>

using namespace std;

//∫·œÚ…®√Ë
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strs_size = strs.size();
        string long_prefix = strs[0];

        if (!strs_size)
            return "";

        for (int i = 1; i < strs_size; i++)
        {
            long_prefix = longestCommonPrefix(long_prefix, strs[i]);

            if (!long_prefix.size())
                break;
        }

        return long_prefix;

    }


    string longestCommonPrefix(const string& str1, const string& str2)
    {
        int length = min(str1.length(), str2.length());
        int index = 0;
        while (index < length && str1[index] == str2[index])
        {
            ++index;
        }

        return str1.substr(0, index);
    }
};


//◊›œÚ…®√Ë
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (!size)
        {
            return "";
        }

        string prefix = strs[0];

        for (int charnum = 0; charnum < prefix.size(); charnum++)
        {
            char a = strs[0][charnum];
            for (int strnum = 1; strnum < size; strnum++)
            {
                if (a != strs[strnum][charnum] || charnum == strs[strnum].size())
                    return strs[0].substr(0, charnum);
            }
        }

        return strs[0];



    }

};