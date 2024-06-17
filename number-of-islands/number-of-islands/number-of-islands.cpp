#include <vector>
#include <queue>

using namespace std;

//DFS
class Solution {
public:
    int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 }; // �ĸ����� �� �� �� ��
    int numIslands(vector<vector<char>>& grid) {
        int x = grid.size();
        int y = grid[0].size();

        vector<vector<bool>> visited = vector<vector<bool>>(x, vector<bool>(y, false));

        int result = 0;
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    result++;
                    dfs(grid, visited, i, j);
                }
            }
        }

        return result;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y)
    {
        for (int i = 0; i < 4; i++)
        {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
            {
                continue;
            }

            if (!visited[nextx][nexty] && grid[nextx][nexty] == '1')
            {
                visited[nextx][nexty] = true;
                dfs(grid, visited, nextx, nexty);
            }
        }
    }
};


//BFS
class Solution {
private:
    int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 }; // �ĸ�����
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        queue<pair<int, int>> que;
        que.push({ x, y });
        visited[x][y] = true; // ֻҪ������У����̱��
        while (!que.empty()) {
            pair<int, int> cur = que.front(); que.pop();
            int curx = cur.first;
            int cury = cur.second;
            for (int i = 0; i < 4; i++) {
                int nextx = curx + dir[i][0];
                int nexty = cury + dir[i][1];
                if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;  // Խ���ˣ�ֱ������
                if (!visited[nextx][nexty] && grid[nextx][nexty] == '1') {
                    que.push({ nextx, nexty });
                    visited[nextx][nexty] = true; // ֻҪ����������̱��
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false));

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    result++; // ����û���ʹ���½�أ�+1
                    bfs(grid, visited, i, j); // ���������ӵ�½�ض������ true
                }
            }
        }
        return result;
    }
};
