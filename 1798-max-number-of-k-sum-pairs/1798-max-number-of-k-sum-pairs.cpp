class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int l = 0;
        int r = nums.size() - 1;

        int ans = 0;
        while (l < r) {
            int sum = nums[l] + nums[r];

            if (sum == k) {
                l++;
                r--;
                ans++;
            } else if (sum > k) {
                r--;
            } else {
                l++;
            }
        }
        
        return ans;
    }
};