#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* dummyNode = new ListNode(-200, head);

        ListNode* cur = dummyNode;


        while (cur->next && cur->next->next)
        {

            if (cur->next->val == cur->next->next->val)
            {
                int x = cur->next->val;

                while (cur->next && cur->next->val == x)
                {
                    cur->next = cur->next->next;

                }
            }
            else
            {
                cur = cur->next;
            }
        }

        return dummyNode->next;
    }
};