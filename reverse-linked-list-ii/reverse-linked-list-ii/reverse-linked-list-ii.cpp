#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    void reverseLinkedList(ListNode* head) {
        // Ҳ����ʹ�õݹ鷴תһ������
        ListNode* pre = nullptr;
        ListNode* cur = head;

        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // ��Ϊͷ�ڵ��п��ܷ����仯��ʹ������ͷ�ڵ���Ա��⸴�ӵķ�������
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode* pre = dummyNode;
        // �� 1 ����������ͷ�ڵ��� left - 1 �������� left �ڵ��ǰһ���ڵ�
        // ����д�� for ѭ�����������
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }

        // �� 2 ������ pre ���� right - left + 1 �������� right �ڵ�
        ListNode* rightNode = pre;
        for (int i = 0; i < right - left + 1; i++) {
            rightNode = rightNode->next;
        }

        // �� 3 �����жϳ�һ����������ȡ����
        ListNode* leftNode = pre->next;
        ListNode* curr = rightNode->next;

        // ע�⣺�ж�����
        pre->next = nullptr;
        rightNode->next = nullptr;

        // �� 4 ����ͬ�� 206 �⣬��ת�����������
        reverseLinkedList(leftNode);

        // �� 5 �����ӻص�ԭ����������
        pre->next = rightNode;
        leftNode->next = curr;
        return dummyNode->next;
    }
};



class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // ���� dummyNode ����һ�������һ������
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* pre = dummyNode;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        ListNode* next;
        //���ѭ����ִ�� right - left �Σ�����Ҫ��ת�Ľڵ�������
        for (int i = 0; i < right - left; i++) {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;

            pre->next = next;

        }
        return dummyNode->next;
    }
};
