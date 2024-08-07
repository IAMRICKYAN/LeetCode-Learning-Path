#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string sum;
        int add = 0;

        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0)
        {
            int aDigit = i == -1 ? 0 : a[i--] - '0';
            int bDigit = j == -1 ? 0 : b[j--] - '0';

            int sDigit = aDigit ^ bDigit ^ add;

            add = (aDigit & bDigit) | (aDigit & add) | (bDigit & add);  // λ������㵱ǰ��λλ
            sum += to_string(sDigit);   // ���µ�ǰλ

        }

        if (add == 1)sum += to_string(1);    // ����λ����󣬽�λλΪ1��˵��������λ
        reverse(sum.begin(), sum.end());    // ����ת

        return sum;

    }
};