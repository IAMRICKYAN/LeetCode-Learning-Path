#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int idx = 0;        // λ����
        uint32_t res = 0;   // ��ת�������ʼΪ0��ʾ����λ��Ϊ0
        // ѭ���������λ1
        while (n > 0) {
            int digit = n & 1;  // ��ȡ��ǰ���λ
            n >>= 1;            // �����λ���Ƶ�
            res |= (digit << (31 - idx++)); // ��������λ��ת����ʵ��λ����ȥ
        }
        return res;
    }
};