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
    inline int getDepth(ListNode* head) { 
        int ans = 0;
        while (head != nullptr) {
            ++ans;
            head = head->next;
        }
        return ans;
    }
    inline ListNode* getTail(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* tail = head;
        while (tail->next != nullptr)
            tail = tail->next;
        return tail;
    }
    inline ListNode* access(ListNode* head, int index) {
        while (index > 0 and head != nullptr) {
            head = head->next;
            --index;
        }
        return head;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int depth = getDepth(head);
        if (depth == 0)
            return head;
        k %= depth;
        if (k == 0)
            return head;
        ListNode* tail = getTail(head);
        tail->next = head;
        ListNode* newTail = access(head, depth - k - 1);
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};