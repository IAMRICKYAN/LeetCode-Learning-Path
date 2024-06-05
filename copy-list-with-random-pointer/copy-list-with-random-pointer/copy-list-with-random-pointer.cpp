#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        // 创建新节点，同时建立原始节点到复制节点的映射
        unordered_map<Node*, Node*> map;
        Node* current = head;
        while (current != nullptr) {
            map[current] = new Node(current->val);
            current = current->next;
        }

        // 设置复制节点的next和random指针
        current = head;
        while (current != nullptr) {
            map[current]->next = map[current->next];
            map[current]->random = map[current->random];
            current = current->next;
        }

        return map[head];
    }
};
