#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 存储每个节点的入度
        vector<int> inDegree(numCourses, 0);
        // 存储有向图
        unordered_map<int, vector<int>> graph;
        // 存储拓扑排序的结果
        vector<int> result;
        // 构建图和入度数组
        for (auto& edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
        }

        // 找到所有入度为0的节点，并将它们加入队列
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // 进行拓扑排序
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            result.push_back(course);
            for (int nextCourse : graph[course]) {
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // 如果结果长度不等于课程数，说明存在环，无法完成所有课程
        if (result.size() != numCourses) {
            return {};
        }

        return result;
    }
};
