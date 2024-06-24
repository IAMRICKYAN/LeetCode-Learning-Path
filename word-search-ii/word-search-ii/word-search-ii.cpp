#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

/**
 * 字典树节点
 */
struct TrieNode {
    unordered_map<char, TrieNode*> children;    // 子节点列表，存储字符和对应的节点
    string str;                 // 如果是尾节点，存储对应的单词
    TrieNode() : str("") {};
};

class Solution {
private:
    TrieNode* root;     // 根节点
    
    /**
     * 将单词word插入字段数root
     */
    void insert(string word) {
        TrieNode* node = root;      // 从根节点开始构造这个word对应的路径节点
        for (auto& char_ : word) {
            if (node->children.find(char_) == node->children.end()) {
                // 字符char_对应的节点不存在，新建一个
                node->children.emplace(char_, new TrieNode());
            }
            // 更新node
            node = node->children[char_];
        }
        node->str = word;   // 尾节点记录单词，用于后序查找的时候快速得到
    }

    /**
     * 深度优先搜索的同时，判断当前路径构成的字符串是否为查找单词
     * @param board: 二维网格
     * @param r: 行号
     * @param c: 列号
     * @param node：当前字符对应的路径节点
     * @param len: 当前路径构成的字符串长度
     * @param res：结果集
     */
    void dfs_Search(vector<vector<char>>& board, int r, int c, TrieNode* node, int len, vector<string>& res) {
        if (len > 10)return;     // 字符串长度超过10，返回
        char ch = board[r][c];  // 获取当前行列对应的字符
        if (node->children.find(ch) == node->children.end())return;  // 当前字符对应的节点不存在，即构造的字符串不在words中
        TrieNode* last = node;  // 记录当前node
        node = node->children[ch];  // 更新当前node为当前字符对应得到的节点
        if (node->str.size() > 0) {
            res.emplace_back(node->str);    // 当前节点记录了一个单词，则得到了一个words中的单词
            node->str = "";     // 匹配了单词，不重复匹配
        };
        if (node->children.empty()) {
            // 当前节点没有后序字符了，那么这个节点一定是某个单词最后一个字符对应的节点。
            // 并且不是其他任何单词的前缀，因此匹配完了之后，可以将这个字符从其父节点的childran列表中删除。
            last->children.erase(ch);
            return;
        }
        len++;  // 更新长度
        board[r][c] = '*';  // 用特殊符号标记当前位置已使用
        // 四个方向转递递归
        if (r - 1 >= 0 && board[r - 1][c] != '*')dfs_Search(board, r - 1, c, node, len, res);
        if (r + 1 < board.size() && board[r + 1][c] != '*')dfs_Search(board, r + 1, c, node, len, res);
        if (c - 1 >= 0 && board[r][c - 1] != '*')dfs_Search(board, r, c - 1, node, len, res);
        if (c + 1 < board[0].size() && board[r][c + 1] != '*')dfs_Search(board, r, c + 1, node, len, res);
        board[r][c] = ch;   // 回溯，这个位置处理完了恢复成原来的字符
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();

        // 构建words的字典树
        root = new TrieNode();
        for (auto& word : words) {
            if (word.size() > m * n)continue;	// 字符串长度超过二维矩阵尺寸，肯定无法构成
            insert(word);
        }

        // 以二维网格的每个位置(i,j)为起点，寻找以其为首字符的所有字符串
        vector<string> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs_Search(board, i, j, root, 0, res);
            }
        }
        return res;
    }
};