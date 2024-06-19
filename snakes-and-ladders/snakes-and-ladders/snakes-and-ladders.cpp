#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();   // ��ȡ����ı߳�
        int target = n * n;     // ��ȡ����ߴ磬Ҳ�����Ҫ����Ŀ�ĵ�
        queue<pair<int, int>> Q;   // ��������BFS����Ŵ������ķ����ź͵���÷���ʱ�������ƶ���
        Q.emplace(1, 0);   // ��ʼ{1,0}��ӣ���ʾ���1��0���ƶ�
        vector<vector<bool>> visited(n, vector<bool>(n));   // ����BFS�����б�Ƿ����Ƿ�������
        // BFS
        while (!Q.empty()) {
            auto node = Q.front();
            Q.pop();
            int curr = node.first, cnt = node.second;   // ��ȡ��ǰ�����ķ�����ƺ͵���÷���������ƶ���
            cnt++;  // �ƶ�����1
            for (int i = curr + 1; i <= min(target, curr + 6); i++) {
                // ö��������һ����������δ�������ķ�����
                int r = n - 1 - (i - 1) / n, c = (i - 1) % n;     // ���ݷ����Ż�ȡ�����ŵ��к���
                c += (n - 1 - 2 * c) * ((n - 1 - r) & 1);       // ����������������
                if (visited[r][c])continue;  // �����������ı��
                visited[r][c] = true;       // ��Ǹñ��������
                int next = board[r][c] == -1 ? i : board[r][c];    // ������������ڵķ������ת�Ƶ��������ӣ�ת�Ƶ���Ӧ��ţ���������ڵ�ǰ���
                if (next == target)return cnt;   // �����յ㣬ֱ�ӷ�����С�ƶ���    
                Q.emplace(next, cnt);  // �������
            }
        }
        return -1;  // �˳�ѭ��˵��û�е���Ŀ�ĵ�
    }
};