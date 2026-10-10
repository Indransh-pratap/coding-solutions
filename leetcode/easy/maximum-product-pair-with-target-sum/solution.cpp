class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
            int n = nums.size();

        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        sort(a.begin(), a.end());

        int l = 0, r = n - 1;
        long long maxProduct = LLONG_MIN;
        vector<int> ans = {-1, -1};

        while (l < r) {
            long long sum = 1LL * a[l].first + a[r].first;

            if (sum == target) {
                long long product =
                    1LL * a[l].first * a[r].first;

                int i = min(a[l].second, a[r].second);
                int j = max(a[l].second, a[r].second);

                if (product > maxProduct) {
                    maxProduct = product;
                    ans = {j, i};
                }

                l++;
                r--;
            }
            else if (sum < target) {
                l++;
            }
            else {
                r--;
            }
        }

        return ans;
    }
};