class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        
        int maxans = 1;
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i]++;
            maxans = max(maxans, dp[i]);
        }
        
        return maxans;
    }
};