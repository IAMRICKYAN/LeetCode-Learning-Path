#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // �洢ÿ���ڵ�����
        vector<int> inDegree(numCourses, 0);
        // �洢����ͼ
        unordered_map<int, vector<int>> graph;
        // �洢��������Ľ��
        vector<int> result;
        // ����ͼ���������
        for (auto& edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
        }

        // �ҵ��������Ϊ0�Ľڵ㣬�������Ǽ������
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // ������������
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

        // ���������Ȳ����ڿγ�����˵�����ڻ����޷�������пγ�
        if (result.size() != numCourses) {
            return {};
        }

        return result;
    }
};
