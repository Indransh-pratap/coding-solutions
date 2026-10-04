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