#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;


// ����һ�����������
class Solution {
public:
    // �����������ܷ����顢ֵ�Լ���ѯ�����ز�ѯ�Ľ��
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        // ����һ��ͼ�����ڱ�ʾ�������еĹ�ϵ
        // ͼ��һ���ַ������ַ�����double��ӳ�䣬��ʾ�ڵ㵽�ڵ�֮���Ȩ��
        unordered_map<string, unordered_map<string, double>> graph;

        // �����������
        int n = equations.size();

        // ����ͼ�����������еĹ�ϵ��ӵ�ͼ��
        for (int i = 0; i < n; i++)
        {
            string s = equations[i][0]; // ���̵���ʼ�ڵ�
            string e = equations[i][1]; // ���̵���ֹ�ڵ�
            double v = values[i];       // ���̵�ֵ

            graph[s][e] = v;            // ���s��e�ıߣ�Ȩ��Ϊv
            graph[e][s] = 1 / v;        // ���e��s�ıߣ�Ȩ��Ϊ1/v
            graph[s][s] = 1.0;          // ���s��s�ıߣ�Ȩ��Ϊ1.0������ѭ����
            graph[e][e] = 1.0;          // ���e��e�ıߣ�Ȩ��Ϊ1.0������ѭ����
        }

        // ����һ�����У����ڿ����������
        queue<pair<string, double>> q;

        // ��ѯ������
        int m = queries.size();

        // ������飬��ʼ��Ϊ-1.0�����ڴ洢��ѯ�Ľ��
        vector<double> ans(m, -1.0);

        // �������в�ѯ
        for (int i = 0; i < m; i++)
        {
            string qx = queries[i][0], qy = queries[i][1]; // ��ǰ��ѯ�������ڵ�

            // �����ѯ�еĽڵ㲻��ͼ�У���������ǰ��ѯ
            if (graph.find(qx) == graph.end() || graph.find(qy) == graph.end()) continue;

            // ����ʼ�ڵ�ͳ�ʼ�˻�1.0�������
            q.emplace(qx, 1.0);

            // ����һ���ѷ��ʼ��ϣ����ڼ�¼�ѷ��ʵĽڵ�
            unordered_set<string> visited{ qx };

            // ���п����������
            while (!q.empty())
            {
                string node = q.front().first;   // ��ǰ�ڵ�
                double mul = q.front().second;   // ����ʼ�ڵ㵽��ǰ�ڵ�ĳ˻�
                q.pop();                         // ������ǰ�ڵ�

                // ������ǰ�ڵ�������ھ�
                for (pair<string, double> neighbor : graph[node])
                {
                    string ngh = neighbor.first;  // �ھӽڵ�
                    double weight = neighbor.second; // ��ǰ�ڵ㵽�ھӽڵ��Ȩ��

                    // ����ҵ��˲�ѯ����ֹ�ڵ㣬����������˳�ѭ��
                    if (ngh == qy) {
                        ans[i] = mul * weight;
                        break;
                    }

                    // ����ھӽڵ�û�б����ʹ�������������
                    if (visited.find(ngh) == visited.end())
                    {
                        visited.emplace(ngh);
                        q.emplace(ngh, mul * weight);
                    }
                }
            }
        }

        // ���ؽ������
        return ans;
    }
};
