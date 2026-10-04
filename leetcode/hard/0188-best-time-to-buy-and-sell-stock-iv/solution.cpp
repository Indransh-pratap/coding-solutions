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