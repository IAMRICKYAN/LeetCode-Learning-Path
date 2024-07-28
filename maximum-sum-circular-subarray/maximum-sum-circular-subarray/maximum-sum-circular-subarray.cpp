#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_s = INT_MIN; // ���������ͣ�����Ϊ��
        int min_s = 0;       // ��С������ͣ�����Ϊ��
        int max_f = 0, min_f = 0, sum = 0;
        for (int x : nums) {
            // �� nums[i-1] ��β��������ѡ��ѡ��ȡ max��+ x = �� x ��β������������
            max_f = max(max_f, 0) + x;
            max_s = max(max_s, max_f);
            // �� nums[i-1] ��β��������ѡ��ѡ��ȡ min��+ x = �� x ��β����С�������
            min_f = min(min_f, 0) + x;
            min_s = min(min_s, min_f);
            sum += x;
        }
        return sum == min_s ? max_s : max(max_s, sum - min_s);
    }
};