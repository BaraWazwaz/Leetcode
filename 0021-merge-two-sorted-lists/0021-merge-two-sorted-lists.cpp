/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* drop(ListNode* head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* tail = head;
        while (list1 and list2) {
            if (list1->val < list2->val) {
                tail = tail->next = new ListNode(list1->val);
                list1 = drop(list1);
            } else {
                tail = tail->next = new ListNode(list2->val);
                list2 = drop(list2);
            }
        }
        while (list1) {
            tail = tail->next = new ListNode(list1->val);
            list1 = drop(list1);
        }
        while (list2) {
            tail = tail->next = new ListNode(list2->val);
            list2 = drop(list2);
        }
        return drop(head);
    }
};