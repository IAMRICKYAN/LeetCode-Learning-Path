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
            return a->val > b->val; // 最小堆
            };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;
        for (auto head : lists) {
            if (head) {
                pq.push(head);
            }
        }

        ListNode dummy{}; // 哨兵节点，作为合并后链表头节点的前一个节点
        auto cur = &dummy;
        while (!pq.empty()) { // 循环直到堆为空
            auto node = pq.top(); // 剩余节点中的最小节点
            pq.pop();
            if (node->next) { // 下一个节点不为空
                pq.push(node->next); // 下一个节点有可能是最小节点，入堆
            }
            cur->next = node; // 合并到新链表中
            cur = cur->next; // 准备合并下一个节点
        }
        return dummy.next; // 哨兵节点的下一个节点就是新链表的头节点
    }
};