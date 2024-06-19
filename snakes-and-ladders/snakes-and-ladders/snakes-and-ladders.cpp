#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();   // 获取方阵的边长
        int target = n * n;     // 获取方阵尺寸，也是最后要到达目的地
        queue<pair<int, int>> Q;   // 队列用于BFS，存放待搜索的方格编号和到达该方格时的最少移动数
        Q.emplace(1, 0);   // 初始{1,0}入队，表示起点1，0次移动
        vector<vector<bool>> visited(n, vector<bool>(n));   // 用于BFS过程中标记方格是否搜索过
        // BFS
        while (!Q.empty()) {
            auto node = Q.front();
            Q.pop();
            int curr = node.first, cnt = node.second;   // 获取当前搜索的方格宾浩和到达该方格的最少移动数
            cnt++;  // 移动数加1
            for (int i = curr + 1; i <= min(target, curr + 6); i++) {
                // 枚举所有下一个可搜索且未搜索过的方格编号
                int r = n - 1 - (i - 1) / n, c = (i - 1) % n;     // 根据方格编号获取这个编号的行和列
                c += (n - 1 - 2 * c) * ((n - 1 - r) & 1);       // 根据行数修正列数
                if (visited[r][c])continue;  // 跳过搜索过的编号
                visited[r][c] = true;       // 标记该编号已搜索
                int next = board[r][c] == -1 ? i : board[r][c];    // 如果这个编号所在的方格可以转移到其他格子，转移到对应编号；否则就是在当前编号
                if (next == target)return cnt;   // 到达终点，直接返回最小移动数    
                Q.emplace(next, cnt);  // 加入队列
            }
        }
        return -1;  // 退出循环说明没有到达目的地
    }
};