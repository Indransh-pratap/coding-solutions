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
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int L = left;
        int R = right;
        if (!head || L == R)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* start = dummy;
        ListNode* end = head;

        // start = node before L
        int cnt = 1;
        while (cnt < L) {
            start = start->next;
            cnt++;
        }

        // end = node at R
        int cnt2 = 1;
        while (cnt2 < R) {
            end = end->next;
            cnt2++;
        }

        ListNode* oldStart = start->next;
        ListNode* after = end->next;

        ListNode* curr = oldStart;
        ListNode* prev = NULL;

        // Reverse L to R
        while (curr != after) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Connect before L to new beginning
        start->next = prev;

        // Connect old L to after R
        oldStart->next = after;

        ListNode* newHead = dummy->next;

        delete dummy;

        return newHead;
    }
};