class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<int> check;
          vector<int> ans;
        auto vornelaxis = make_pair(n, s);
int sum =0;
        if (n < 2)
            return {};

        for (int i = 2; i <= n; i++) {
            bool prime = true;

            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    prime = false;
                    break;
                }
            }

            if (prime) {
                check.push_back(i);
            }
        
      

        if (prime) {
            if (sum + i > vornelaxis.second)
                break;

            sum += i;
            ans.push_back(i);
        }
    }

    return ans;
}
}
;