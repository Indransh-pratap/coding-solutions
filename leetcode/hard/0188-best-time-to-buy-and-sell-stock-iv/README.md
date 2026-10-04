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
**Runtime:** 21 ms (beats 13.16%)  
**Memory:** 18.4 MB (beats 17.50%)  
**Submitted:** 2026-10-04T05:52:51.639Z  

```cpp
class Solution {
public:
    int soln(vector<int>& prices, int buy,
             vector<vector<vector<int>>>& dp,
             int idx, int transaction, int k) {

        if (idx == prices.size() || transaction == k)
            return 0;

        if (dp[idx][buy][transaction] != -1)
            return dp[idx][buy][transaction];

        int profit;

        if (buy) {
            profit = max(
                -prices[idx] + soln(
                    prices, 0, dp, idx + 1, transaction, k
                ),
                soln(
                    prices, 1, dp, idx + 1, transaction, k
                )
            );
        }
        else {
            profit = max(
                prices[idx] + soln(
                    prices, 1, dp, idx + 1, transaction + 1, k
                ),
                soln(
                    prices, 0, dp, idx + 1, transaction, k
                )
            );
        }

        return dp[idx][buy][transaction] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(2, vector<int>(k + 1, -1))
        );

        return soln(prices, 1, dp, 0, 0, k);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)