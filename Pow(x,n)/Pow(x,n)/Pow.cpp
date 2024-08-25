class Solution {
public:
    double myPow(double x, int N) {

        double ans = 1;
        long long n = N;

        if (n < 0)
        {
            n = -n;
            x = 1 / x;
        }

        while (n)
        {
            if (n & 1)
            {
                ans *= x;
            }
            x *= x;

            n >>= 1;
        }

        return ans;

    }
};