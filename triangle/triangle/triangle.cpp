#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();

        for (int i = 1; i < row; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (j == 0)
                {
                    triangle[i][j] += triangle[i - 1][j];
                }
                else
                {
                    if (i == j)
                    {
                        triangle[i][j] += triangle[i - 1][j - 1];
                    }
                    else
                    {
                        triangle[i][j] += min(triangle[i - 1][j], triangle[i-1][j - 1]);
                    }
                }
            }
        }

        // �󷵻�ֵ����ײ�������е���Сֵ
        int minSum = triangle[row - 1][0];
        for (auto e : triangle[row - 1])
        {
            if (minSum > e) minSum = e;
        }
        return minSum;

    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        //���¶��ϱ���
        for (int i = row - 2; i >= 0; --i) // ���һ������ʼֵ ���������
        {
            for (int j = 0; j <= i; ++j)
            {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
};