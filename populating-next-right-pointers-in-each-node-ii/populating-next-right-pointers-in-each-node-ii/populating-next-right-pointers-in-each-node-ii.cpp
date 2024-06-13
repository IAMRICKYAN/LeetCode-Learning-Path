#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    vector<Node*> pre;


public:
    Node* connect(Node* root) {
        dfs(root, 0);
        return root;
    }

    void dfs(Node* node, int depth)
    {
        if (node == nullptr)
        {
            return;
        }

        if (depth == pre.size()) //此时的node相当于一层最左边的节点
        {
            pre.emplace_back(node);
        }
        else
        {
            pre[depth]->next = node; //当node不是这一层最左边的节点时
            pre[depth] = node;
        }

        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
};