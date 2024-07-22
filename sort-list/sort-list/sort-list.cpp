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
     * �Ը�����������й鲢����
    */
    ListNode* mergeSort(ListNode* head) {
        // �������Ϊ�ջ�ֻ��һ���ڵ㣬��������ֱ�ӷ���
        if (!head || !head->next) {
            return head;
        }
        // ��ȡ������м�ڵ㣬�ֱ�������������������
        ListNode* mid = getMid(head);
        ListNode* rightSorted = mergeSort(mid->next);   // ������������
        if (mid)mid->next = nullptr;                     // �Ͽ�����������
        ListNode* leftSorted = mergeSort(head);         // ������������
        return mergeTwoLists(leftSorted, rightSorted);  // �����������Ȼ���򣬺ϲ��������������
    }

    /**
     * ��ȡ��headΪͷ�ڵ�������м�ڵ�
     * ���������Ϊ�������������м���Ǹ��ڵ�
     * ���������Ϊż���������м俿����Ǹ��ڵ�
    */
    ListNode* getMid(ListNode* head) {
        if (!head)return head;
        ListNode* slow = head, * fast = head->next;          // ����ָ�룬��ָ���ʼΪ
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;    // ��ָ��ÿ���ƶ������ڵ�
            slow = slow->next;          // ��ָ��ÿ���ƶ�һ���ڵ�
        }
        return slow;    // ��ָ�뵽������β��ʱ����ָ�뼴ָ���м�ڵ�
    }

    /**
     * �ϲ�������������list1��list2
    */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();   // αͷ�ڵ㣬���ڶ�λ�ϲ������ͷ�ڵ�
        ListNode* node = dummy;             // ������ǰ�����һ���ڵ㣬��ʼΪαͷ�ڵ�
        // ֱ�����������������ˣ��ϲ�����
        while (list1 != nullptr || list2 != nullptr) {
            int val1 = list1 == nullptr ? 50001 : list1->val;   // �������1�Ѿ������꣬val1ȡ���ֵ����֤����2�Ľڵ㱻ѡ��       
            int val2 = list2 == nullptr ? 50001 : list2->val;   // �������2�Ѿ������꣬val2ȡ���ֵ����֤����1�Ľڵ㱻ѡ�� 
            if (val1 < val2) {
                // ����1�Ľڵ�ֵ��С�����뵽�ϲ���������������1ָ��Ľڵ�
                node->next = list1;
                list1 = list1->next;
            }
            else {
                // ����2�Ľڵ�ֵ��С�����뵽�ϲ���������������2ָ��Ľڵ�
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;    // ���ºϲ�����ǰ�����һ���ڵ�ָ��
        }
        return dummy->next;       // αͷ�ڵ����һ���ڵ㼴Ϊ�ϲ������ͷ�ڵ�
    }
};