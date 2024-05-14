#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int sum = 0;
        int size = prices.size();
        for (int i = size - 1; i > 0; i--)
        {
            sum += max(0, (prices[i] - prices[i - 1]));
        }

        return sum;
    }
};