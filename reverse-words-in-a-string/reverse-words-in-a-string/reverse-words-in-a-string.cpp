#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> words;
        string word;

        // 使用 stringstream 分割单词
        while (ss >> word) {
            words.push_back(word);
        }

        // 反转单词顺序并连接成字符串
        string reversed;
        for (int i = words.size() - 1; i >= 0; i--) {
            reversed += words[i];
            if (i != 0) {
                reversed += " ";
            }
        }

        return reversed;
    }
};