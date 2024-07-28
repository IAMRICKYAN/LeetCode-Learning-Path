#include <vector>
#include <queue>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val; // ��С��
            };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;
        for (auto head : lists) {
            if (head) {
                pq.push(head);
            }
        }

        ListNode dummy{}; // �ڱ��ڵ㣬��Ϊ�ϲ�������ͷ�ڵ��ǰһ���ڵ�
        auto cur = &dummy;
        while (!pq.empty()) { // ѭ��ֱ����Ϊ��
            auto node = pq.top(); // ʣ��ڵ��е���С�ڵ�
            pq.pop();
            if (node->next) { // ��һ���ڵ㲻Ϊ��
                pq.push(node->next); // ��һ���ڵ��п�������С�ڵ㣬���
            }
            cur->next = node; // �ϲ�����������
            cur = cur->next; // ׼���ϲ���һ���ڵ�
        }
        return dummy.next; // �ڱ��ڵ����һ���ڵ�����������ͷ�ڵ�
    }
};