class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;    // ͳ��[1, n]������5�ĸ���
        // ֻҪn���ڵ���5����һ������5�ı���
        while (n >= 5) {
            n /= 5;     // ÿ��ѭ����n / 5 ����ͳ��n���ж���5^i�ı�����i��ѭ������
            res += n;   // ��Щ���������Էֽ�һ������5
        }
        return res;
    }
};