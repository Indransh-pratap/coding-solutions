# Best Time to Buy and Sell Stock IV

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `ith` day, and an integer `k`.

Find the maximum profit you can achieve. You may complete at most `k` transactions: i.e. you may buy at most `k` times and sell at most `k` times.

 **Note:**  You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

 **Example 1:** 

```
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

```

 **Example 2:** 

```
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

```

 

 **Constraints:** 

- 1 <= k <= 100
- 1 <= prices.length <= 1000
- 0 <= prices[i] <= 1000

## Solution

**Language:** C++  
**Runtime:** 4 ms (beats 70.46%)  
**Memory:** 14.6 MB (beats 74.52%)  
**Submitted:** 2026-10-04T06:02:15.352Z  

```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> next(
            2, vector<int>(k + 1, 0)
        );

        vector<vector<int>> curr(
            2, vector<int>(k + 1, 0)
        );

        for (int idx = n - 1; idx >= 0; idx--) {

            for (int buy = 0; buy <= 1; buy++) {

                for (int transaction = 0;
                     transaction < k;
                     transaction++) {

                    if (buy) {
                        curr[buy][transaction] = max(
                            -prices[idx] +
                                next[0][transaction],
                            next[1][transaction]
                        );
                    }
                    else {
                        curr[buy][transaction] = max(
                            prices[idx] +
                                next[1][transaction + 1],
                            next[0][transaction]
                        );
                    }
                }
            }

            next = curr;
        }

        return next[1][0];
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)