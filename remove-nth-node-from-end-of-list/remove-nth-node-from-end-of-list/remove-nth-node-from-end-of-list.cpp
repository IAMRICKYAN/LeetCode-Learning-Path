#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//遍历寻找长度
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* copyhead = new ListNode(-1);
        copyhead->next = head;
        int size = 0;

        ListNode* cur = copyhead;
        while (cur != nullptr)
        {
            size++;
            cur = cur->next;
        }

        ListNode* pre = copyhead;
        for (int i = 0; i < size - n - 1; i++)
        {
            pre = pre->next;
        }

        pre->next = pre->next->next;
        
        return copyhead->next;
    }
};

//栈
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* copyhead = new ListNode(-1);
        copyhead->next = head;

        stack<ListNode*> stk;

        ListNode* cur = copyhead;
        while (cur != nullptr)
        {
            stk.push(cur);
            cur = cur->next;
        }

        for (int i = 0; i < n; i++)
        {
            stk.pop();
        }

        ListNode* pre = stk.top();
        pre->next = pre->next->next;

        ListNode* ans = copyhead->next;
        delete copyhead;

        return ans;
    }
};

//双指针
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        for (int i = 0; i < n; ++i) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* ans = dummy->next;

        delete dummy;
        return ans;
    }
};
