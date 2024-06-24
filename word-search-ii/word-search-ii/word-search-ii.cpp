#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

/**
 * �ֵ����ڵ�
 */
struct TrieNode {
    unordered_map<char, TrieNode*> children;    // �ӽڵ��б��洢�ַ��Ͷ�Ӧ�Ľڵ�
    string str;                 // �����β�ڵ㣬�洢��Ӧ�ĵ���
    TrieNode() : str("") {};
};

class Solution {
private:
    TrieNode* root;     // ���ڵ�
    
    /**
     * ������word�����ֶ���root
     */
    void insert(string word) {
        TrieNode* node = root;      // �Ӹ��ڵ㿪ʼ�������word��Ӧ��·���ڵ�
        for (auto& char_ : word) {
            if (node->children.find(char_) == node->children.end()) {
                // �ַ�char_��Ӧ�Ľڵ㲻���ڣ��½�һ��
                node->children.emplace(char_, new TrieNode());
            }
            // ����node
            node = node->children[char_];
        }
        node->str = word;   // β�ڵ��¼���ʣ����ں�����ҵ�ʱ����ٵõ�
    }

    /**
     * �������������ͬʱ���жϵ�ǰ·�����ɵ��ַ����Ƿ�Ϊ���ҵ���
     * @param board: ��ά����
     * @param r: �к�
     * @param c: �к�
     * @param node����ǰ�ַ���Ӧ��·���ڵ�
     * @param len: ��ǰ·�����ɵ��ַ�������
     * @param res�������
     */
    void dfs_Search(vector<vector<char>>& board, int r, int c, TrieNode* node, int len, vector<string>& res) {
        if (len > 10)return;     // �ַ������ȳ���10������
        char ch = board[r][c];  // ��ȡ��ǰ���ж�Ӧ���ַ�
        if (node->children.find(ch) == node->children.end())return;  // ��ǰ�ַ���Ӧ�Ľڵ㲻���ڣ���������ַ�������words��
        TrieNode* last = node;  // ��¼��ǰnode
        node = node->children[ch];  // ���µ�ǰnodeΪ��ǰ�ַ���Ӧ�õ��Ľڵ�
        if (node->str.size() > 0) {
            res.emplace_back(node->str);    // ��ǰ�ڵ��¼��һ�����ʣ���õ���һ��words�еĵ���
            node->str = "";     // ƥ���˵��ʣ����ظ�ƥ��
        };
        if (node->children.empty()) {
            // ��ǰ�ڵ�û�к����ַ��ˣ���ô����ڵ�һ����ĳ���������һ���ַ���Ӧ�Ľڵ㡣
            // ���Ҳ��������κε��ʵ�ǰ׺�����ƥ������֮�󣬿��Խ�����ַ����丸�ڵ��childran�б���ɾ����
            last->children.erase(ch);
            return;
        }
        len++;  // ���³���
        board[r][c] = '*';  // ��������ű�ǵ�ǰλ����ʹ��
        // �ĸ�����ת�ݵݹ�
        if (r - 1 >= 0 && board[r - 1][c] != '*')dfs_Search(board, r - 1, c, node, len, res);
        if (r + 1 < board.size() && board[r + 1][c] != '*')dfs_Search(board, r + 1, c, node, len, res);
        if (c - 1 >= 0 && board[r][c - 1] != '*')dfs_Search(board, r, c - 1, node, len, res);
        if (c + 1 < board[0].size() && board[r][c + 1] != '*')dfs_Search(board, r, c + 1, node, len, res);
        board[r][c] = ch;   // ���ݣ����λ�ô������˻ָ���ԭ�����ַ�
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();

        // ����words���ֵ���
        root = new TrieNode();
        for (auto& word : words) {
            if (word.size() > m * n)continue;	// �ַ������ȳ�����ά����ߴ磬�϶��޷�����
            insert(word);
        }

        // �Զ�ά�����ÿ��λ��(i,j)Ϊ��㣬Ѱ������Ϊ���ַ��������ַ���
        vector<string> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs_Search(board, i, j, root, 0, res);
            }
        }
        return res;
    }
};