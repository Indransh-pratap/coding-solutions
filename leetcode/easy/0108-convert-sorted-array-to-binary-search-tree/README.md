# Convert Sorted Array to Binary Search Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer array `nums` where the elements are sorted in  **ascending order**, convert  *it to a   height-balanced binary search tree*.

 

 **Example 1:** 

```
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

```

 **Example 2:** 

```
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

```

 

 **Constraints:** 

- 1 <= nums.length <= 104
- -104 <= nums[i] <= 104
- nums is sorted in a strictly increasing order.

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 76.85%)  
**Memory:** 22.8 MB (beats 82.75%)  
**Submitted:** 2026-10-05T18:07:38.156Z  

```cpp
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Handle the base case for an empty array
        if (nums.empty()) return nullptr;
        
        // Call the recursive helper function with the full array range
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* buildBST(const vector<int>& nums, int left, int right) {
        // Base case: if the left index crosses the right index, there are no elements left
        if (left > right) return nullptr;
        
        // Choose the middle element to maintain balance
        int mid = left + (right - left) / 2;
        
        // Create the root node with the middle value
        TreeNode* root = new TreeNode(nums[mid]);
        
        // Recursively build the left and right subtrees
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);
        
        return root;
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)