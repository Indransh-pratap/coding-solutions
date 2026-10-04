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

        int next[2][3] = {};
        int curr[2][3] = {};

        for (int i = n - 1; i >= 0; i--) {

            for (int buy = 0; buy <= 1; buy++) {

                for (int transaction = 0; transaction < 2; transaction++) {

                    if (buy) {
                        curr[buy][transaction] = max(
                            -prices[i] + next[0][transaction],
                            next[1][transaction]
                        );
                    }
                    else {
                        curr[buy][transaction] = max(
                            prices[i] + next[1][transaction + 1],
                            next[0][transaction]
                        );
                    }
                }
            }

            // current becomes next
            for (int b = 0; b < 2; b++)
                for (int t = 0; t < 3; t++)
                    next[b][t] = curr[b][t];
        }

        return next[1][0];
    }

};