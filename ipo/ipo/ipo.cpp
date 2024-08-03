#include <vector>
#include <queue>
#include <numeric> 

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // 生成索引序列
        int n = capital.size();
        vector<int> indexes(n);
        iota(indexes.begin(), indexes.end(), 0);
        // 根据资本值对索引进行升序排序    
        sort(indexes.begin(), indexes.end(), [&](int i, int j) {
            return capital[i] < capital[j];
            });
        priority_queue<int> pq;     // 维护堆内利润值的大顶堆
        int i = 0;
        while (k-- > 0) {
            // 将启动资本小于等于当前资本的项目的利润加入大顶堆
            while (i < n && capital[indexes[i]] <= w) {
                pq.emplace(profits[indexes[i++]]);
            }
            if (pq.empty())break;     // 没有可以启动的项目，后面启动资本更大的项目也无法启动，退出
            w += pq.top();       // 选择启动资本满足条件的项目中利润最大的那个，更新w
            pq.pop();
        }
        return w;
    }
};