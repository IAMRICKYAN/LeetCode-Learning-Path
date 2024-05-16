#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int nums_size = nums.size();
        vector<int> prefix(nums_size + 1);
        vector<int> lastfix(nums_size + 1);
        vector<int> answer(nums_size);
        prefix[0] = 1;
        lastfix[nums_size - 1] = 1;

        for(int i=1;i<nums_size;i++)
        {           
                prefix[i] = nums[i - 1] * prefix[i - 1];      
                lastfix[nums_size - i -1] = nums[nums_size - i ] * lastfix[nums_size - i];
  
        }

        for(int i=0;i<nums_size;i++)
        {            
            answer[i] = prefix[i] * lastfix[i];
        }

        return answer;
    }
};