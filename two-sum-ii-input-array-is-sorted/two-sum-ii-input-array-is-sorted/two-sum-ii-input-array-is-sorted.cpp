#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int left = 0;
        int right = numbers.size() -1;
        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (target == sum)
            {
                return { left + 1,right + 1 };
            }
            else
            {
                if (sum < target)
                {
                    left++;
                }
                else
                {
                    if (sum > target )
                        right--;
                }
            }

        }

        return {};

    }
};