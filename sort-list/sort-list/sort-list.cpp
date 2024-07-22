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
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }

    /**
     * 对给定的链表进行归并排序
    */
    ListNode* mergeSort(ListNode* head) {
        // 如果链表为空或只有一个节点，无需排序直接返回
        if (!head || !head->next) {
            return head;
        }
        // 获取链表的中间节点，分别对左右子链表进行排序
        ListNode* mid = getMid(head);
        ListNode* rightSorted = mergeSort(mid->next);   // 排序右子链表
        if (mid)mid->next = nullptr;                     // 断开两段子链表
        ListNode* leftSorted = mergeSort(head);         // 排序左子链表
        return mergeTwoLists(leftSorted, rightSorted);  // 两个子链表必然有序，合并两个有序的链表
    }

    /**
     * 获取以head为头节点的链表中间节点
     * 如果链表长度为奇数，返回最中间的那个节点
     * 如果链表长度为偶数，返回中间靠左的那个节点
    */
    ListNode* getMid(ListNode* head) {
        if (!head)return head;
        ListNode* slow = head, * fast = head->next;          // 快慢指针，慢指针初始为
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;    // 快指针每次移动两个节点
            slow = slow->next;          // 慢指针每次移动一个节点
        }
        return slow;    // 快指针到达链表尾部时，慢指针即指向中间节点
    }

    /**
     * 合并两个有序链表list1和list2
    */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();   // 伪头节点，用于定位合并链表的头节点
        ListNode* node = dummy;             // 新链表当前的最后一个节点，初始为伪头节点
        // 直到两个链表都遍历完了，合并结束
        while (list1 != nullptr || list2 != nullptr) {
            int val1 = list1 == nullptr ? 50001 : list1->val;   // 如果链表1已经遍历完，val1取最大值，保证链表2的节点被选择到       
            int val2 = list2 == nullptr ? 50001 : list2->val;   // 如果链表2已经遍历完，val2取最大值，保证链表1的节点被选择到 
            if (val1 < val2) {
                // 链表1的节点值更小，加入到合并链表，并更新链表1指向的节点
                node->next = list1;
                list1 = list1->next;
            }
            else {
                // 链表2的节点值更小，加入到合并链表，并更新链表2指向的节点
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;    // 更新合并链表当前的最后一个节点指向
        }
        return dummy->next;       // 伪头节点的下一个节点即为合并链表的头节点
    }
};