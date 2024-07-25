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
        int n = grid.size();        // ����ߴ�
        preSum.resize(n + 1, vector<int>(n + 1));   // ��ʼ��ǰ׺������
        // �����ά����ǰ׺��
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                preSum[i + 1][j + 1] = preSum[i][j + 1] + preSum[i + 1][j] - preSum[i][j] + grid[i][j];
            }
        }
        // �����Ĳ���
        return constructFromArea(grid, 0, 0, n - 1, n - 1);
    }
private:
    vector<vector<int>> preSum;     // ��ά����ǰ׺��
    /**
     * ���ɸ�������[(ltr, ltc), (rtr, rtc)]������
     * @param grid: �������
     * @param ltr: ��Χ�������Ͻ��б�
     * @param ltc: ��Χ�������Ͻ��б�
     * @param rtr: ��Χ�������½��б�
     * @param rtc: ��Χ�������½��б�
    */
    Node* constructFromArea(vector<vector<int>>& grid, int ltr, int ltc, int rbr, int rbc) {
        // areaSum[(si, sj), (i,j)] = preSum[i+1][j+1] �C preSum[si][j+1] �C preSum[i+1][sj] + preSum[si][sj]
        int areaSum = preSum[rbr + 1][rbc + 1] - preSum[ltr][rbc + 1] - preSum[rbr + 1][ltc] + preSum[ltr][ltc];    // ��������Χ��
        int areaCnts = (rbr - ltr + 1) * (rbc - ltc + 1);       // ��������Ԫ�����
        if (areaSum == 0 || areaSum == areaCnts) {
            // ��������Ϊ0���������ȫΪ0���������͵��������������������ȫΪ1���������������Ҷ�ӽڵ�
            return new Node(areaSum / areaCnts, true);
        }
        int mr = ltr + (rbr - ltr + 1) / 2;     // �м��е��к�
        int mc = ltc + (rbc - ltc + 1) / 2;     // �м��е��к�
        // ����ǰ���򻮷ֳ��ĸ������򣬵ݹ���������
        return new Node(0, false,
            constructFromArea(grid, ltr, ltc, mr - 1, mc - 1),
            constructFromArea(grid, ltr, mc, mr - 1, rbc),
            constructFromArea(grid, mr, ltc, rbr, mc - 1),
            constructFromArea(grid, mr, mc, rbr, rbc)
        );
    }
};