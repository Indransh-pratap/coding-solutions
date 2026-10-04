# Best Time to Buy and Sell Stock with Transaction Fee

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day, and an integer `fee` representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

 **Note:** 

- You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
- The transaction fee is only charged once for each stock purchase and sale.

 

 **Example 1:** 

```
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

```

 **Example 2:** 

```
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6

```

 

 **Constraints:** 

- 1 <= prices.length <= 5 * 104
- 1 <= prices[i] < 5 * 104
- 0 <= fee < 5 * 104

## Solution

**Language:** C++  
**Runtime:** 128 ms (beats 16.01%)  
**Memory:** 108.7 MB (beats 9.25%)  
**Submitted:** 2026-10-04T06:11:07.504Z  

```cpp
class Solution {
public:
    int soln(vector<int>& prices, int buy, vector<vector<int>>& dp, int idx,
             int fee) {
        int profit = 0;
        if (idx == prices.size())
            return 0;

        //

        if (dp[idx][buy] != -1)
            return dp[idx][buy];
        if (buy) {
            profit =
                max(-prices[idx] - fee + soln(prices, 0, dp, idx + 1, fee),
                    soln(prices, 1, dp, idx + 1, fee));
        }

        else {
            profit = max(prices[idx] + soln(prices, 1, dp, idx + 1, fee),
                         soln(prices, 0, dp, idx + 1, fee));
        }

        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return soln(prices, 1, dp, 0, fee);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)