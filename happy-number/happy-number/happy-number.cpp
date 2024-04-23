#include<iostream>


using namespace std;

int getSum(int number)
{
    int sum = 0;
    while (number > 0)
    {
        int perNumber = number % 10;
        sum += perNumber * perNumber;
        number = number / 10;
    }

    return sum;
}


class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = getSum(slow);
            fast = getSum(fast);
            fast = getSum(fast);

        } while (slow != fast);
        return slow == 1;
    }
};