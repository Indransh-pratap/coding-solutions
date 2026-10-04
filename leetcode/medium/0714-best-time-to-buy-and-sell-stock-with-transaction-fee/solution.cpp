class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int buy = 0;
        int sell = 0;

        for (int i = prices.size() - 1; i >= 0; i--) {

            int currBuy = max(
                -prices[i] - fee + sell,
                buy
            );

            int currSell = max(
                prices[i] + buy,
                sell
            );

            buy = currBuy;
            sell = currSell;
        }

        return buy;
    }
};