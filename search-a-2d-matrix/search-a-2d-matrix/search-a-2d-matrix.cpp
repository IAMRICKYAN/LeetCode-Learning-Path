#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int column = matrix[0].size();
        int row = matrix.size();
        
            int left = -1, right = row*column;
            while (left + 1 < right)
            {
                int mid = left + (right - left) / 2;
                if (matrix[mid/column][mid%column] == target)
                {
                    return true;
                }

                if (matrix[mid / column][mid % column] < target)
                {
                    left = mid ;
                }
                else
                {
                    right = mid;
                }
            }
        

        return false;
    }
};