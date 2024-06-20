#include <string>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        unordered_set<string> string_set(bank.begin(), bank.end());

        queue<string> Q;
        Q.push(startGene);

        unordered_set<string> visited;
        visited.emplace(startGene);

        int step = 0;

        while (!Q.empty())
        {
            int size = Q.size();
            while (size > 0)
            {
                string cur = Q.front();
                Q.pop();

                if (cur == endGene)
                {
                    return step;
                }
                for (char gene : "ACGT")
                {
                    for (int j = 0; j < cur.size(); j++)
                    {
                        string next = cur;
                        next[j] = gene;

                        if (string_set.count(next) && !visited.count(next))
                        {
                            Q.push(next);
                            visited.emplace(next);
                        }
                    }
                }

                size--;
            }
            step++;
        }

        return -1;
    }
};
