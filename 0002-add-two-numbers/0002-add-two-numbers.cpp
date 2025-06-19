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
    inline int add(int x, int y, int& carry) {
        int sum = x + y + carry;
        carry = sum > 9;
        if (carry)
            sum -= 10;
        return sum;
    }
    inline void append(ListNode*& tail, int val) {
        tail = tail->next = new ListNode(val);
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, temp;
        {
            int x = l1->val, y = l2->val;
            temp = add(x, y, carry);
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* head = new ListNode(temp);
        ListNode* tail = head;
        while (l1 and l2) {
            int x = l1->val, y = l2->val;
            int sum = add(x, y, carry);
            append(tail, sum);
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int x = l1->val;
            int sum = add(x, 0, carry);
            append(tail, sum);
            l1 = l1->next;
        }
        while (l2) {
            int y = l2->val;
            int sum = add(0, y, carry);
            append(tail, sum);
            l2 = l2->next;
        }
        if (carry) 
            append(tail, carry);
        return head;
    }
};