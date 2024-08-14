class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;    // 统计[1, n]的因子5的个数
        // 只要n大于等于5，就一定包含5的倍数
        while (n >= 5) {
            n /= 5;     // 每次循环，n / 5 是在统计n中有多少5^i的倍数，i是循环次数
            res += n;   // 这些倍数都可以分解一个因子5
        }
        return res;
    }
};