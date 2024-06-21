#include <iostream>
#include <vector>

using namespace std;

class WordDictionary {
private:
    bool isEnd;
    vector<WordDictionary*> child;

public:
    WordDictionary() : child(26), isEnd(false) {}

    void addWord(string word) {
        WordDictionary* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->child[ch] == nullptr) {
                node->child[ch] = new WordDictionary();
            }
            node = node->child[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        return searchInNode(word, this);
    }

private:
    bool searchInNode(const string& word, WordDictionary* node) {
        for (int i = 0; i < word.size(); ++i) {
            char ch = word[i];
            if (ch == '.') {
                // 遍历所有可能的字符
                for (int j = 0; j < 26; ++j) {
                    if (node->child[j] != nullptr && searchInNode(word.substr(i + 1), node->child[j])) {
                        return true;
                    }
                }
                return false;
            }
            else {
                ch -= 'a';
                if (node->child[ch] == nullptr) {
                    return false;
                }
                node = node->child[ch];
            }
        }
        return node->isEnd;
    }
};