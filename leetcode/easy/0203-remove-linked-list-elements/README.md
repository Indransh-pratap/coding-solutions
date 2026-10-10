# Remove Linked List Elements

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the `head` of a linked list and an integer `val`, remove all the nodes of the linked list that has `Node.val == val`, and return  *the new head*.

 

 **Example 1:** 

```
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

```

 **Example 2:** 

```
Input: head = [], val = 1
Output: []

```

 **Example 3:** 

```
Input: head = [7,7,7,7], val = 7
Output: []

```

 

 **Constraints:** 

- The number of nodes in the list is in the range [0, 104].
- 1 <= Node.val <= 50
- 0 <= val <= 50

## Solution

**Language:** C++  
**Runtime:** 4 ms (beats 4.14%)  
**Memory:** 20.2 MB (beats 41.07%)  
**Submitted:** 2026-10-10T06:39:13.197Z  

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
```

---

[View on LeetCode](https://leetcode.com/problems/remove-linked-list-elements/)