# Rotate List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `head` of a linked list, rotate the list to the right by `k` places.

 

 **Example 1:** 

```
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

```

 **Example 2:** 

```
Input: head = [0,1,2], k = 4
Output: [2,0,1]

```

 

 **Constraints:** 

- The number of nodes in the list is in the range [0, 500].
- -100 <= Node.val <= 100
- 0 <= k <= 2 * 109

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 16.3 MB (beats 63.35%)  
**Submitted:** 2026-10-09T10:19:35.255Z  

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
```

---

[View on LeetCode](https://leetcode.com/problems/rotate-list/)