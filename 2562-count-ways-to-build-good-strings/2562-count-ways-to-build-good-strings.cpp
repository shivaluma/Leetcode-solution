class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>  dp(high+1, 0);
        dp[0] = 1;
        int mod = 1000000007;
        for (int end = 1; end <= high; end++) {
            if (end >= zero) {
                dp[end] += dp[end-zero];
            }

            if (end >= one) {
                dp[end] += dp[end-one];
            }

            dp[end] %= mod;
        }

        int ans = 0;

        for (int i = low; i <= high; i++) {
            ans += dp[i];
            ans %= mod;
        }

        return ans;
    }
};