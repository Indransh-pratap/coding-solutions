class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> next(
            2, vector<int>(k + 1, 0)
        );

        vector<vector<int>> curr(
            2, vector<int>(k + 1, 0)
        );

        for (int idx = n - 1; idx >= 0; idx--) {

            for (int buy = 0; buy <= 1; buy++) {

                for (int transaction = 0;
                     transaction < k;
                     transaction++) {

                    if (buy) {
                        curr[buy][transaction] = max(
                            -prices[idx] +
                                next[0][transaction],
                            next[1][transaction]
                        );
                    }
                    else {
                        curr[buy][transaction] = max(
                            prices[idx] +
                                next[1][transaction + 1],
                            next[0][transaction]
                        );
                    }
                }
            }

            next = curr;
        }

        return next[1][0];
    }
};