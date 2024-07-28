#include <vector>
#include <iostream>
#include <ranges>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN; // ע��𰸿����Ǹ��������ܳ�ʼ���� 0
        int f = 0;
        for (int x : nums) {
            f = max(f, 0) + x;
            ans = max(ans, f);
        }
        return ans;
    }
};