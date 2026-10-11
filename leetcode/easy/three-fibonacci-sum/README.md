# Q1. Three Fibonacci Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given an integer `n`.

The  **Fibonacci sequence**  starts with 0 and 1, and each subsequent number is the sum of the previous two numbers. Its first few terms are `0, 1, 1, 2, 3, 5, 8, 13,...`.

Return `true` if `n` can be expressed as the sum of  **three consecutive terms**  in the Fibonacci sequence, and `false` otherwise.

 

 **Example 1:** 

 **Input:**  n = 16

 **Output:**  true

 **Explanation:** 

The three consecutive terms 3, 5, and 8 have a sum of `3 + 5 + 8 = 16`.

 **Example 2:** 

 **Input:**  n = 8

 **Output:**  false

 **Explanation:** 

Although `1 + 2 + 5 = 8`, these terms are not consecutive in the Fibonacci sequence. No three consecutive terms have a sum of 8.

 **Example 3:** 

 **Input:**  n = 2

 **Output:**  true

 **Explanation:** 

The first three terms have a sum of `0 + 1 + 1 = 2`.

 

 **Constraints:** 

- 1 <= n <= 109

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8 MB  
**Submitted:** 2026-10-11T03:01:23.199Z  

```cpp
class Solution {
public:
    bool threeFibonacciSum(int n) {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);

        dp[0] = 0;
        if (n >= 1)
            dp[1] = 1;

        while (true) {
            int sz = dp.size();
            long long next = dp[sz - 1] + dp[sz - 2];

            if (next > n)
                break;
            dp.push_back(next);
        }

        for (int i = 0; i + 2 < dp.size(); i++) {
            if (dp[i] + dp[i + 1] + dp[i + 2] == n)
                return true;
        }

        return false;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/three-fibonacci-sum/)