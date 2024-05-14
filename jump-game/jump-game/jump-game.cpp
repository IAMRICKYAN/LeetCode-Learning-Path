#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int nums_size = nums.size();
        int maxstep = 0;
        for (int i = 0; i < nums_size - 1; i++)
        {
            if (i <= maxstep) //����Ҫ�ж��Ƿ��ܵ����±�λ��
            {
                maxstep = max((nums[i] + i), maxstep);
            }

            if (maxstep >= nums_size - 1)
                return true;
        }

        return false;
    }
};
