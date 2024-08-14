#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> res(digits.begin(), digits.end());  // 拷贝一个digits
        res[n - 1]++;   // 最后一位+1
        int add = 0;    // 进位位
        for (int i = n - 1; i >= 0; i--) {
            res[i] += add;      // 除了最后一位，其他每一位都需要累加进位位；初始add=0，最后一位累加进位无影响
            add = res[i] / 10;  // 根据当前位的值，判断是否产生进位
            res[i] %= 10;       // 取模值
            if (add == 0)return res; // 如果没有产生进位，剩下的位不会再变化，直接返回
        }
        // 最高位产生进位，这个数字一定是9...9 + 1，结果就是10...0
        // 多产生了一位高位1，其他位都为0
        vector<int> res_(n + 1);
        res_[0] = 1;
        return res_;
    }
};