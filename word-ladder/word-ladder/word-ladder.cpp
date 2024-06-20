#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    char AllChar[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> string_set(wordList.begin(), wordList.end());
        if (!string_set.count(endWord)) return 0;
        queue<string> Q;
        Q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        int ans = 1;

        while (!Q.empty())
        {
            int size = Q.size();

            while (size > 0)
            {
                string cur = Q.front();
                Q.pop();

                if (cur == endWord)
                {
                    return ans;
                }

                for (auto& ch : AllChar)
                {
                    for (int i = 0; i < cur.size(); i++)
                    {
                        string next = cur;
                        next[i] = ch;

                        if (string_set.count(next) && !visited.count(next))
                        {
                            cout << next << endl;
                            Q.push(next);
                            visited.insert(next);
                        }
                    }

                }

                size--;
            }
            ans++;
        }
        return 0;
    }
};