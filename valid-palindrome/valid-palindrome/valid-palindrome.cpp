#include <iostream>
#include <string>

using namespace std;

//����API
class Solution {
public:
    bool isPalindrome(string S) {
        string str;

        for (auto& s : S)
        {
            if (isalnum(s))
            {
                str += tolower(s);
            }
        }

        string str_rev(str.rbegin(), str.rend());

        if (str == str_rev)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

//˫ָ��
class Solution {
public:
    bool isPalindrome(string S) {
        string str;

        for (auto& s : S)
        {
            if (isalnum(s))
            {
                str += tolower(s);
            }
        }
        int size = str.length();
        int left = 0, right = size - 1;

        while (left < right)
        {
            if (str[left++] != str[right--])
                return false;

        }

        return true;

    }

};

