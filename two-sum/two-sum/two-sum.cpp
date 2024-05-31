#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> store;

        for (int i = 0; i < nums.size(); i++)
        {
            int component = target - nums[i];

            if (store.find(component) != store.end())
            {
                int a[] = { i , store[component] };

                return { a , a + 2 };
            }
            store[nums[i]] = i;

        }

        return {};

    }
};