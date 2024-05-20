#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        vector<string> rows(numRows);

        //��ת���־
        int flag = 1;
        //���±�����
        int idxRows = 0;

        for (int i = 0; i < s.size(); i++)
        {
            rows[idxRows].push_back(s[i]);
            //�������±�
            idxRows += flag;
            if (idxRows == numRows - 1 || idxRows == 0)
            {
                flag = -flag;
            }
        }

        string res;
        for (auto& row : rows)
        {
            res += row;
        }

        return res;
    }
};