#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:

    unordered_map<int,Node*> node_set;

    Node* cloneGraph(Node* node) {
        
        if (node == nullptr)
        {
            return node;
        }

        if (node_set.count(node->val)) return node_set[node->val];

        Node* p = new Node(node->val);
        node_set[node->val] = p;

        vector<Node*> neighbor = node->neighbors;

        for (int i = 0; i < neighbor.size(); i++)
        {
            p->neighbors.emplace_back(cloneGraph(neighbor[i]));
        }

        return p;
    }
};