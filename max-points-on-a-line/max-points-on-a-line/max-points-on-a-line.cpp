#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    const int K = 20001;    // ����б�ʶ�Ԫ���ŵ�ϵ��

    /**
     * շת�������a��b�����Լ��
     */
    int gcd(int a, int b) {
        if (a == 1 || b == 1)return 1;
        while (b > 0) {
            int tmp = a;
            a = b;
            b = tmp % b;
        }
        return a;
    }

    /**
     * ��ȡ����dx��dy��б�ʶ�Ԫ�飨dx, dy�����
     * б�ʱ�� id = dx * 20001 + dy
     * Ϊ����ȷ��ʾб�ʣ���Ҫ��dx��dy����Լ�֣�������ͬʱ�������Լ��
     * б���������������ǿ��Ը���б�ʷ��ŶԱ�ż���������������
     * �ر�ģ�����dx = 0��dy = 0��������dy��dx��ֵΪ���٣�б�ʶ���һ��Ϊ0���ޣ���������INT_MAX���ֵ��ʾ����
     */
    int getK(int dx, int dy) {
        if (dx == 0)return 0;        // dxΪ0 ����б�ʱ��Ϊ0
        if (dy == 0)return INT_MAX;  // dyΪ0������б�ʱ��Ϊ����ֵ
        int sign = dx * dy > 0 ? 1 : -1;    // ��ȡб�ʱ�ŷ���
        dx = abs(dx);
        dy = abs(dy);
        int g = gcd(dx, dy);    // ��dx��dyȡ����ֵ��ȡ���Լ��
        dx /= g;
        dy /= g;    // �õ�б�ʷ��Ӻͷ�ĸ����ֵ
        // std::cout << "dx: " << dx << " dy: " << dy << std::endl;
        return sign * (dx * K + dy);    // ���ؾ���ֵ���
    }

public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2)return n;		// �������������һ������
        int res = 0;
        for (int i = 0; i < n; i++) {
            // �����ǰ����ߵ�������ʣ��Ҫö�ٵĵ�������һ�������ֵ
            if (res >= n - i)
                break;
            // ��ȡ(x1, y1)����ֱ�ߵ�������
            int x1 = points[i][0], y1 = points[i][1];
            int maxCnt = 1;                 // ͳ��(x1, y1)����ֱ�ߵ�������
            unordered_map<int, int> kCnts;  // ͳ��(x1, y1)���ڸ�ֱ�ߵĵ���
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int k = getK(x2 - x1, y2 - y1);     // ��ȡ(x1, y1)��(x2, y2)��б�ʱ��
                if (kCnts.find(k) == kCnts.end()) {
                    kCnts[k] = 1;   // ���б���״γ��֣���ʼֵΪ1����ʾ(x1, y1)�����
                }
                kCnts[k]++; // �ۼ�1����ʾ����(x2, y2)�����
            }
            // ͳ��(x1, y1)���ߵ�����ߵ���
            for (auto& kv : kCnts) {
                maxCnt = max(maxCnt, kv.second);
            }
            // ���½��
            res = max(res, maxCnt);
        }
        return res;
    }
};