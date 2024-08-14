#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> res(digits.begin(), digits.end());  // ����һ��digits
        res[n - 1]++;   // ���һλ+1
        int add = 0;    // ��λλ
        for (int i = n - 1; i >= 0; i--) {
            res[i] += add;      // �������һλ������ÿһλ����Ҫ�ۼӽ�λλ����ʼadd=0�����һλ�ۼӽ�λ��Ӱ��
            add = res[i] / 10;  // ���ݵ�ǰλ��ֵ���ж��Ƿ������λ
            res[i] %= 10;       // ȡģֵ
            if (add == 0)return res; // ���û�в�����λ��ʣ�µ�λ�����ٱ仯��ֱ�ӷ���
        }
        // ���λ������λ���������һ����9...9 + 1���������10...0
        // �������һλ��λ1������λ��Ϊ0
        vector<int> res_(n + 1);
        res_[0] = 1;
        return res_;
    }
};