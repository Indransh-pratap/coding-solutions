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
    ListNode* removeElements(ListNode* head, int val) {
        int X = val;
         while (head != NULL && head->val == X) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    ListNode* curr = head;

    while (curr != NULL && curr->next != NULL) {
        if (curr->next->val == X) {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }

    return head;
    }
};