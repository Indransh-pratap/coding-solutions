class Solution {
public:
    int maxProfit(vector<int>& prices) {

        vector<int> buy(2, 0);
        vector<int> sell(2, 0);
        vector<int> curr(2, 0);

        for (int i = prices.size() - 1; i >= 0; i--) {

            // curr[0] = buy[i]
            curr[0] = max(
                buy[0],              // buy[i+1]
                -prices[i] + sell[0] // sell[i+1]
            );

            // curr[1] = sell[i]
            curr[1] = max(
                sell[0],             // sell[i+1]
                prices[i] + buy[1]   // buy[i+2]
            );

            // shift AFTER calculations
            buy[1] = buy[0];
            buy[0] = curr[0];

            sell[0] = curr[1];
        }

        return buy[0];
    }
};