#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//动态规划
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if (size == 0)
            return 0;

        vector<int> leftmax(size);
        leftmax[0] = height[0];
        for (int i = 1; i < size; i++)
        {
            leftmax[i] = max(leftmax[i - 1], height[i]);
        }

        vector<int> rightmax(size);
        rightmax[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--)
        {
            rightmax[i] = max(rightmax[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < size; i++)
        {
            ans += min(leftmax[i], rightmax[i]) - height[i];

        }

        return ans;


    }
};

//双指针
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        int left = 0; int right = size - 1;
        int leftmax = 0;
        int rightmax = 0;


        while (left < right)
        {
            leftmax = max(leftmax, height[left]);
            rightmax = max(rightmax, height[right]);

            if (height[left] < height[right])
            {
                ans += leftmax - height[left];
                ++left;
            }
            else
            {
                ans += rightmax - height[right];
                --right;
            }

        }
        return ans;
    }
};

//单调栈
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        stack<int> stk;
        int ans = 0;

        for (int right = 0; right < size; right++)
        {
            while (!stk.empty() && height[i] > height[stk.top()])
            {
                int top = stk.top();
                stk.pop();
                if (stk.empty())
                    break;

                int left = stk.top();
                int currwidth = right - left - 1;
                int currheight = min(height[right], height[left]) - height[top];
                ans += currwidth * currheight;
            }
            stk.push(i);
        }
    }
};


