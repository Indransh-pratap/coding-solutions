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
    ListNode* rotateRight(ListNode* head, int k) {

         if (head == NULL || head->next == NULL || k == 0)
        return head;
        int cnt = 1;
        ListNode* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
            cnt++;
        }
        int R = k;

        R = R % cnt;
        if (R == 0)
            return head;

        // Find the new tail: (cnt - R - 1) steps from head
        ListNode* newTail = head;
        for (int i = 0; i < cnt - R - 1; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;

        newTail->next = NULL;
        tail->next = head;

        return newHead;
    }
};