#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        if (points.size() == 0)
        {
            return 0;
        }

        sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[1] < v[1];
            });

        int num = 1;
        int pos = points[0][1];

        for (auto& point : points)
        {
            
            if (point[0] > pos)
            {
                num++;
                pos = point[1];
            }
        }

        return num;

    }
};