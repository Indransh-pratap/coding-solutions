# Next Greater Node In Linked List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given the `head` of a linked list with `n` nodes.

For each node in the list, find the value of the  **next greater node**. That is, for each node, find the value of the first node that is next to it and has a  **strictly larger**  value than it.

Return an integer array `answer` where `answer[i]` is the value of the next greater node of the `ith` node (**1-indexed**). If the `ith` node does not have a next greater node, set `answer[i] = 0`.

 

 **Example 1:** 

```
Input: head = [2,1,5]
Output: [5,5,0]

```

 **Example 2:** 

```
Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]

```

 

 **Constraints:** 

- The number of nodes in the list is n.
- 1 <= n <= 104
- 1 <= Node.val <= 109

## Solution

**Language:** C++  
**Runtime:** 4 ms (beats 74.10%)  
**Memory:** 47 MB (beats 34.53%)  
**Submitted:** 2026-10-11T03:56:45.335Z  

```cpp

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<pair<int, int>> st;

        ListNode* curr = head;
        int idx = 0;

        while (curr != nullptr) {
            ans.push_back(0);

            while (!st.empty() && curr->val > st.top().first) {
                ans[st.top().second] = curr->val;
                st.pop();
            }

            st.push({curr->val, idx});
            curr = curr->next;
            idx++;
        }

        return ans;
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/next-greater-node-in-linked-list/)