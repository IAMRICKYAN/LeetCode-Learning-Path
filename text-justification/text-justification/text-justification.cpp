#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    // blank ���س���Ϊ n ���ɿո���ɵ��ַ���
    string blank(int n) {
        return string(n, ' ');
    }

    // join ������ sep ƴ�� [left, right) ��Χ�ڵ� words ��ɵ��ַ���
    string join(vector<string>& words, int left, int right, string sep) {
        string s = words[left];
        for (int i = left + 1; i < right; ++i) {
            s += sep + words[i];
        }
        return s;
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int right = 0, n = words.size();
        while (true) {
            int left = right; // ��ǰ�еĵ�һ�������� words ��λ��
            int sumLen = 0; // ͳ����һ�е��ʳ���֮��
            // ѭ��ȷ����ǰ�п��ԷŶ��ٵ��ʣ�ע�ⵥ��֮��Ӧ������һ���ո�
            while (right < n && sumLen + words[right].length() + right - left <= maxWidth) {
                sumLen += words[right++].length();
            }

            // ��ǰ�������һ�У���������룬�ҵ���֮��Ӧֻ��һ���ո�����ĩ���ʣ��ո�
            if (right == n) {
                string s = join(words, left, n, " ");
                ans.emplace_back(s + blank(maxWidth - s.length()));
                return ans;
            }

            int numWords = right - left;
            int numSpaces = maxWidth - sumLen;

            // ��ǰ��ֻ��һ�����ʣ��õ�������룬����ĩ���ʣ��ո�
            if (numWords == 1) {
                ans.emplace_back(words[left] + blank(numSpaces));
                continue;
            }

            // ��ǰ�в�ֻһ������
            int avgSpaces = numSpaces / (numWords - 1);
            int extraSpaces = numSpaces % (numWords - 1);
            string s1 = join(words, left, left + extraSpaces + 1, blank(avgSpaces + 1)); // ƴ�Ӷ����һ���ո�ĵ���
            string s2 = join(words, left + extraSpaces + 1, right, blank(avgSpaces)); // ƴ�����൥��
            ans.emplace_back(s1 + blank(avgSpaces) + s2);
        }
    }
};

