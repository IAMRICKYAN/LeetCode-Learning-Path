#include <vector>
#include <queue>
#include <numeric> 

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // ������������
        int n = capital.size();
        vector<int> indexes(n);
        iota(indexes.begin(), indexes.end(), 0);
        // �����ʱ�ֵ������������������    
        sort(indexes.begin(), indexes.end(), [&](int i, int j) {
            return capital[i] < capital[j];
            });
        priority_queue<int> pq;     // ά����������ֵ�Ĵ󶥶�
        int i = 0;
        while (k-- > 0) {
            // �������ʱ�С�ڵ��ڵ�ǰ�ʱ�����Ŀ���������󶥶�
            while (i < n && capital[indexes[i]] <= w) {
                pq.emplace(profits[indexes[i++]]);
            }
            if (pq.empty())break;     // û�п�����������Ŀ�����������ʱ��������ĿҲ�޷��������˳�
            w += pq.top();       // ѡ�������ʱ�������������Ŀ�����������Ǹ�������w
            pq.pop();
        }
        return w;
    }
};