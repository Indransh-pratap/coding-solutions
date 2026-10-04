class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> buy(n + 2, 0);
        vector<int> sell(n + 2, 0);

        for (int i = n - 1; i >= 0; i--) {

            buy[i] = max(
                buy[i + 1],
                -prices[i] + sell[i + 1]
            );

            sell[i] = max(
                sell[i + 1],
                prices[i] + buy[i + 2]
            );
        }

        return buy[0];
    }
};