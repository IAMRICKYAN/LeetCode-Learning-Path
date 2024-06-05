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

        // �����½ڵ㣬ͬʱ����ԭʼ�ڵ㵽���ƽڵ��ӳ��
        unordered_map<Node*, Node*> map;
        Node* current = head;
        while (current != nullptr) {
            map[current] = new Node(current->val);
            current = current->next;
        }

        // ���ø��ƽڵ��next��randomָ��
        current = head;
        while (current != nullptr) {
            map[current]->next = map[current->next];
            map[current]->random = map[current->random];
            current = current->next;
        }

        return map[head];
    }
};
