# Best Time to Buy and Sell Stock III

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

Find the maximum profit you can achieve. You may complete  **at most two transactions**.

 **Note:**  You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

 **Example 1:** 

```
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
```

 **Example 2:** 

```
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

```

 **Example 3:** 

```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

```

 

 **Constraints:** 

- 1 <= prices.length <= 105
- 0 <= prices[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 397 ms (beats 43.99%)  
**Memory:** 211.5 MB (beats 42.95%)  
**Submitted:** 2026-10-04T05:43:31.929Z  

```cpp
class Solution {
public:
    // int soln(vector<int>& prices, int buy, vector<vector<int>>& dp, int idx,
    //          int transaction) {

    //     if (idx == prices.size())
    //         return 0;
    //     if (transaction == 2)
    //         return 0;

    //            if (dp[idx][buy] != -1) return dp[idx][buy];

    //     int profit = 0;
    //     if (buy) {
    //         profit =
    //             max(-prices[idx] + soln(prices, 0, dp, idx + 1, transaction),
    //                 soln(prices, 1, dp, idx + 1, transaction));
    //     }

    //     else {
    //         profit =
    //             max(prices[idx] + soln(prices, 1, dp, idx + 1, transaction + 1),
    //                 soln(prices, 0, dp, idx + 1, transaction));
    //     }
    //      return dp[idx][buy] = profit;
    // }  recursive version 
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n, vector<int>(2, -1));

    //    return  soln(prices, 1, dp, 0, 0);
    // }

    int maxProfit(vector<int>& prices) {
    int n = prices.size();

    vector<vector<vector<int>>> dp(
        n + 1,
        vector<vector<int>>(2, vector<int>(3, 0))
    );

    for (int i = n - 1; i >= 0; i--) {

        for (int buy = 0; buy <= 1; buy++) {

            for (int transaction = 0; transaction < 2; transaction++) {

                if (buy) {
                    dp[i][buy][transaction] =
                        max(
                            -prices[i] + dp[i + 1][0][transaction],
                            dp[i + 1][1][transaction]
                        );
                }
                else {
                    dp[i][buy][transaction] =
                        max(
                            prices[i] + dp[i + 1][1][transaction + 1],
                            dp[i + 1][0][transaction]
                        );
                }
            }
        }
    }

    return dp[0][1][0];
}
};
```

---

[View on LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)