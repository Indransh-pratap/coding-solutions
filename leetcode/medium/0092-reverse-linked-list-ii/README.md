# Reverse Linked List II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return  *the reversed list*.

 

 **Example 1:** 

```
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

```

 **Example 2:** 

```
Input: head = [5], left = 1, right = 1
Output: [5]

```

 

 **Constraints:** 

- The number of nodes in the list is n.
- 1 <= n <= 500
- -500 <= Node.val <= 500
- 1 <= left <= right <= n

 

 **Follow up:**  Could you do it in one pass?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 11.4 MB (beats 38.41%)  
**Submitted:** 2026-10-09T06:23:28.190Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/reverse-linked-list-ii/)