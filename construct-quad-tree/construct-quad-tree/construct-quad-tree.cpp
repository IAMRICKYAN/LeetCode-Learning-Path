#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();        // 矩阵尺寸
        preSum.resize(n + 1, vector<int>(n + 1));   // 初始化前缀和数组
        // 计算二维矩阵前缀和
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                preSum[i + 1][j + 1] = preSum[i][j + 1] + preSum[i + 1][j] - preSum[i][j] + grid[i][j];
            }
        }
        // 构造四叉树
        return constructFromArea(grid, 0, 0, n - 1, n - 1);
    }
private:
    vector<vector<int>> preSum;     // 二维数组前缀和
    /**
     * 生成给定区域[(ltr, ltc), (rtr, rtc)]的子树
     * @param grid: 输入矩阵
     * @param ltr: 范围矩阵左上角行标
     * @param ltc: 范围矩阵左上角列标
     * @param rtr: 范围矩阵右下角行标
     * @param rtc: 范围矩阵右下角列标
    */
    Node* constructFromArea(vector<vector<int>>& grid, int ltr, int ltc, int rbr, int rbc) {
        // areaSum[(si, sj), (i,j)] = preSum[i+1][j+1] – preSum[si][j+1] – preSum[i+1][sj] + preSum[si][sj]
        int areaSum = preSum[rbr + 1][rbc + 1] - preSum[ltr][rbc + 1] - preSum[rbr + 1][ltc] + preSum[ltr][ltc];    // 计算区域范围和
        int areaCnts = (rbr - ltr + 1) * (rbc - ltc + 1);       // 计算区域单元格个数
        if (areaSum == 0 || areaSum == areaCnts) {
            // 如果区域和为0，则该区域全为0；如果区域和等于区域格子数，则区域全为1；这两种情况就是叶子节点
            return new Node(areaSum / areaCnts, true);
        }
        int mr = ltr + (rbr - ltr + 1) / 2;     // 中间行的行号
        int mc = ltc + (rbc - ltc + 1) / 2;     // 中间列的列号
        // 将当前区域划分成四个子区域，递归生成子树
        return new Node(0, false,
            constructFromArea(grid, ltr, ltc, mr - 1, mc - 1),
            constructFromArea(grid, ltr, mc, mr - 1, rbc),
            constructFromArea(grid, mr, ltc, rbr, mc - 1),
            constructFromArea(grid, mr, mc, rbr, rbc)
        );
    }
};