#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {


        s.append(1, ' ');
        unordered_map<char, string> word_pattern;
        unordered_map<string, char> word_pattern1;
        int index = 0;
        int num = 0;
        string word;
        //abc hh ab
        int i = 0;
        for (auto& ch : s)
        {
            if (ch == ' ')
            {
                
                word = s.substr(index, num);
                cout << "index现在是 " << index;
                index = index + num + 1; //这里的 +1 就是要把空格的长度也算上
                cout << " 变换为后是 " << index << endl;

                num = -1; //当出现第一个空白后,与下面的num++抵消 也可以使用continue.

                cout << word_pattern.count(pattern[i]) << "相对于的word = " << word << endl;
                

                if ( ((word_pattern.count(pattern[i])) && (word_pattern[pattern[i]] != word)) || ( word_pattern1.count(word) && word_pattern1[word] != pattern[i]))
                {
                    //cout << s << "a" << endl;
                    return false;
                }
                word_pattern[pattern[i]] = word;
                word_pattern1[word] = pattern[i];

                cout << "i的值是 i=" << i << endl;
                i++;
            }
            num++;
        }

        if (i != pattern.size())
        {
            return false;
        }

        return true;
    }
};

class Solution2 {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> map;
        unordered_map<string, char> rmap;
        stringstream ss(str); string s;
        for (char c : pattern) {
            //!(ss >> s) 这行语句判断是否存在单词的长度比字符串长
            //当 ss 中没有更多的单词时，ss >> s 操作会失败，
            //但循环仍然会继续尝试处理 pattern 中的下一个字符 "g"。然而，由于 s 仍然是之前最后一个提取的单词 "dog"
            //这会导致rmap 的检查失败
            if (!(ss >> s) || (map.count(c) == 1 && map[c] != s) || (rmap.count(s) == 1 && rmap[s] != c)) return false;
            map[c] = s; rmap[s] = c;
        }
        //下面这行代码判断是否字符串比单词长
        //因为这个方法是遍历单词,所以最后要判断是否字符串比单词长
        return (ss >> s) ? false : true;
    }
};

class Solution3 {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> map;
        unordered_map<string, char> rmap;
        stringstream ss(str); string s;
        for (char c : pattern) {
            ss >> s;
            if ((map.count(c) == 1 && map[c] != s) || (rmap.count(s) == 1 && rmap[s] != c)) return false;
            map[c] = s; rmap[s] = c;
        }
        return (ss >> s) ? false : true;
    }
};




int main()
{
    string pattern = "abbacg", s = "dog cat cat dog";
    Solution3 sol;
    if (sol.wordPattern(pattern, s))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}