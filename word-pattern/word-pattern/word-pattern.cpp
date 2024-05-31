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
                cout << "index������ " << index;
                index = index + num + 1; //����� +1 ����Ҫ�ѿո�ĳ���Ҳ����
                cout << " �任Ϊ���� " << index << endl;

                num = -1; //�����ֵ�һ���հ׺�,�������num++���� Ҳ����ʹ��continue.

                cout << word_pattern.count(pattern[i]) << "����ڵ�word = " << word << endl;
                

                if ( ((word_pattern.count(pattern[i])) && (word_pattern[pattern[i]] != word)) || ( word_pattern1.count(word) && word_pattern1[word] != pattern[i]))
                {
                    //cout << s << "a" << endl;
                    return false;
                }
                word_pattern[pattern[i]] = word;
                word_pattern1[word] = pattern[i];

                cout << "i��ֵ�� i=" << i << endl;
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
            //!(ss >> s) ��������ж��Ƿ���ڵ��ʵĳ��ȱ��ַ�����
            //�� ss ��û�и���ĵ���ʱ��ss >> s ������ʧ�ܣ�
            //��ѭ����Ȼ��������Դ��� pattern �е���һ���ַ� "g"��Ȼ�������� s ��Ȼ��֮ǰ���һ����ȡ�ĵ��� "dog"
            //��ᵼ��rmap �ļ��ʧ��
            if (!(ss >> s) || (map.count(c) == 1 && map[c] != s) || (rmap.count(s) == 1 && rmap[s] != c)) return false;
            map[c] = s; rmap[s] = c;
        }
        //�������д����ж��Ƿ��ַ����ȵ��ʳ�
        //��Ϊ��������Ǳ�������,�������Ҫ�ж��Ƿ��ַ����ȵ��ʳ�
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