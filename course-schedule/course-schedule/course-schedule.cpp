#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

public:
    void dfs(int u) {
        visited[u] = 1;
        for (int v : edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            }
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return valid;
    }
};

//BFS
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //所有课程的入度
        vector<int> ingree(numCourses, 0);
        //保存课程和先修课程之间的关系
        unordered_map<int, vector<int>> preCourse;
        for (int i = 0; i < prerequisites.size(); ++i) {
            preCourse[prerequisites[i][0]].push_back(prerequisites[i][1]);
            ingree[prerequisites[i][1]]++;
        }

        queue<int> zero_ingree;
        int count = 0;
        for (int i = 0; i < numCourses; ++i) {
            //所有入度为0的课程入队列
            if (!ingree[i]) {
                zero_ingree.push(i);
                ++count;
            }
        }

        while (!zero_ingree.empty()) {
            int cur_course = zero_ingree.front();
            zero_ingree.pop();
            for (int i = 0; i < preCourse[cur_course].size(); ++i) {
                //当前入度为0的课程对应的先修课程入度减1
                --ingree[preCourse[cur_course][i]];
                if (!ingree[preCourse[cur_course][i]]) {
                    //入度为0的课程入队列
                    zero_ingree.push(preCourse[cur_course][i]);
                    ++count;
                }
            }
        }
        //所有课程的入度减为0，说明课程可以修完
        if (count == numCourses) return true;
        return false;
    }
};