class Solution {
public:
    bool threeFibonacciSum(int n) {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);

        dp[0] = 0;
        if (n >= 1)
            dp[1] = 1;

        while (true) {
            int sz = dp.size();
            long long next = dp[sz - 1] + dp[sz - 2];

            if (next > n)
                break;
            dp.push_back(next);
        }

        for (int i = 0; i + 2 < dp.size(); i++) {
            if (dp[i] + dp[i + 1] + dp[i + 2] == n)
                return true;
        }

        return false;
    }
};