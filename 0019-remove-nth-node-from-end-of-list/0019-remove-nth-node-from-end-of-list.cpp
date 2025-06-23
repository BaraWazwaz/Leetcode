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
    void dropNext(ListNode* trav) {
        if (trav == nullptr or trav->next == nullptr)
            return;
        ListNode* holder = trav->next;
        trav->next = trav->next->next;
        delete holder;
    }
    int recur(ListNode* trav, int del) {
        if (trav == nullptr)
            return 0;
        int backwardsIndex = recur(trav->next, del) + 1;
        if (backwardsIndex == del + 1)
            dropNext(trav);
        return backwardsIndex;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = recur(head, n);
        if (size == n) {
            ListNode* holder = head;
            head = head->next;
            delete holder;
        }
        return head;
    }
};