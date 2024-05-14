
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = 1e9;
        int maxprofit = 0;

        for (auto& price : prices)
        {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(minprice, price);
        }

        if (maxprofit > 0)
            return maxprofit;
        else
            return 0;
    }

};