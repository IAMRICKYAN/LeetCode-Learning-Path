#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int i = 0;



        while (i < n)
        {
            int gasall = 0;
            int costall = 0;
            int cnt = 0;

            while (cnt < n)
            {
                int j = (i + cnt) % n;
                gasall += gas[j];
                costall += cost[j];

                if (gasall < costall)
                    break;


                cnt++;
            }

            if (cnt == n)
                return i;
            else
                i = i + cnt + 1;

        }

        return -1;


    }

};

