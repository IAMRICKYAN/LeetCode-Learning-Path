#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 2);
        for (int i = 0; i < n; i++) {
            f[i + 2] = max(f[i + 1], f[i] + nums[i]);
        }
        return f[n + 1];
    }
};