#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    const int K = 20001;    // 生成斜率二元组编号的系数

    /**
     * 辗转相除法求a和b的最大公约数
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
     * 获取给定dx和dy的斜率二元组（dx, dy）编号
     * 斜率编号 id = dx * 20001 + dy
     * 为了正确表示斜率，需要对dx和dy进行约分，即二者同时除以最大公约数
     * 斜率区分正负，我们可以根据斜率符号对编号加上正负进行区分
     * 特别的，对于dx = 0（dy = 0），无论dy（dx）值为多少，斜率都是一样为0（∞），我们用INT_MAX最大值表示无穷
     */
    int getK(int dx, int dy) {
        if (dx == 0)return 0;        // dx为0 返回斜率编号为0
        if (dy == 0)return INT_MAX;  // dy为0，返回斜率编号为极大值
        int sign = dx * dy > 0 ? 1 : -1;    // 获取斜率编号符号
        dx = abs(dx);
        dy = abs(dy);
        int g = gcd(dx, dy);    // 将dx和dy取绝对值后取最大公约数
        dx /= g;
        dy /= g;    // 得到斜率分子和分母绝对值
        // std::cout << "dx: " << dx << " dy: " << dy << std::endl;
        return sign * (dx * K + dy);    // 返回绝对值编号
    }

public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2)return n;		// 不超过两个点的一定共线
        int res = 0;
        for (int i = 0; i < n; i++) {
            // 如果当前最大共线点数超过剩下要枚举的点数，则一定是最大值
            if (res >= n - i)
                break;
            // 获取(x1, y1)所在直线的最大点数
            int x1 = points[i][0], y1 = points[i][1];
            int maxCnt = 1;                 // 统计(x1, y1)所在直线的最大点数
            unordered_map<int, int> kCnts;  // 统计(x1, y1)所在各直线的点数
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int k = getK(x2 - x1, y2 - y1);     // 获取(x1, y1)和(x2, y2)的斜率编号
                if (kCnts.find(k) == kCnts.end()) {
                    kCnts[k] = 1;   // 这个斜率首次出现，初始值为1，表示(x1, y1)这个点
                }
                kCnts[k]++; // 累加1，表示加入(x2, y2)这个点
            }
            // 统计(x1, y1)在线的最大共线点数
            for (auto& kv : kCnts) {
                maxCnt = max(maxCnt, kv.second);
            }
            // 更新结果
            res = max(res, maxCnt);
        }
        return res;
    }
};