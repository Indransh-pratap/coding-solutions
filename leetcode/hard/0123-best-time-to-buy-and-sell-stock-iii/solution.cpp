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