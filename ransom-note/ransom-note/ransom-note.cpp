#include <vector>
#include <unordered_map>
#include <string>

using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> rans;
        unordered_map<char,int> mag;

        for (int i = 0; i < magazine.size(); i++)
        {
            mag[magazine[i]]++;
        }

        for (int i = 0; i < ransomNote.size(); i++)
        {
            if (++rans[ransomNote[i]] > mag[ransomNote[i]])
            {
                return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        vector<int> cnt(26);
        for (auto& c : magazine) {
            cnt[c - 'a']++;
        }
        for (auto& c : ransomNote) {
            cnt[c - 'a']--;
            if (cnt[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};