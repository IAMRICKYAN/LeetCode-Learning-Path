#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }

        //unordered_set<int> store;

        unordered_set<int> store(nums.begin(), nums.end());

        /*for (const int& num : nums) {
            store.insert(num);
        }*/
        int maxlength = 0;

        for (int num : nums)
        {
            if (store.find(num) != store.end())
            {
                store.erase(num);
                int length = 1;
                int left = num - 1;
                int right = num + 1;

                while (store.find(left) != store.end())
                {
                    store.erase(left);
                    left--;
                    length++;
                }

                while (store.find(right) != store.end())
                {
                    store.erase(right);
                    right++;
                    length++;
                }

                maxlength = max(maxlength, length);
            }
        }

        return maxlength;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};

