#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;


// 定义一个解决方案类
class Solution {
public:
    // 主函数，接受方程组、值以及查询，返回查询的结果
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        // 创建一个图，用于表示方程组中的关系
        // 图是一个字符串到字符串到double的映射，表示节点到节点之间的权重
        unordered_map<string, unordered_map<string, double>> graph;

        // 方程组的数量
        int n = equations.size();

        // 构建图，将方程组中的关系添加到图中
        for (int i = 0; i < n; i++)
        {
            string s = equations[i][0]; // 方程的起始节点
            string e = equations[i][1]; // 方程的终止节点
            double v = values[i];       // 方程的值

            graph[s][e] = v;            // 添加s到e的边，权重为v
            graph[e][s] = 1 / v;        // 添加e到s的边，权重为1/v
            graph[s][s] = 1.0;          // 添加s到s的边，权重为1.0（自身循环）
            graph[e][e] = 1.0;          // 添加e到e的边，权重为1.0（自身循环）
        }

        // 创建一个队列，用于宽度优先搜索
        queue<pair<string, double>> q;

        // 查询的数量
        int m = queries.size();

        // 结果数组，初始化为-1.0，用于存储查询的结果
        vector<double> ans(m, -1.0);

        // 遍历所有查询
        for (int i = 0; i < m; i++)
        {
            string qx = queries[i][0], qy = queries[i][1]; // 当前查询的两个节点

            // 如果查询中的节点不在图中，则跳过当前查询
            if (graph.find(qx) == graph.end() || graph.find(qy) == graph.end()) continue;

            // 将起始节点和初始乘积1.0放入队列
            q.emplace(qx, 1.0);

            // 创建一个已访问集合，用于记录已访问的节点
            unordered_set<string> visited{ qx };

            // 进行宽度优先搜索
            while (!q.empty())
            {
                string node = q.front().first;   // 当前节点
                double mul = q.front().second;   // 从起始节点到当前节点的乘积
                q.pop();                         // 弹出当前节点

                // 遍历当前节点的所有邻居
                for (pair<string, double> neighbor : graph[node])
                {
                    string ngh = neighbor.first;  // 邻居节点
                    double weight = neighbor.second; // 当前节点到邻居节点的权重

                    // 如果找到了查询的终止节点，则计算结果并退出循环
                    if (ngh == qy) {
                        ans[i] = mul * weight;
                        break;
                    }

                    // 如果邻居节点没有被访问过，则将其加入队列
                    if (visited.find(ngh) == visited.end())
                    {
                        visited.emplace(ngh);
                        q.emplace(ngh, mul * weight);
                    }
                }
            }
        }

        // 返回结果数组
        return ans;
    }
};
