#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int idx = 0;        // 位索引
        uint32_t res = 0;   // 反转结果，初始为0表示所有位都为0
        // 循环处理到最高位1
        while (n > 0) {
            int digit = n & 1;  // 获取当前最低位
            n >>= 1;            // 将最低位右移掉
            res |= (digit << (31 - idx++)); // 将这个最低位反转到它实际位置上去
        }
        return res;
    }
};