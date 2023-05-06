class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mod = 1e9+7;
        vector<int> powerof2(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            powerof2[i] = (powerof2[i-1] * 2) % mod;
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int idx = binarySearch(nums, target - nums[i]);
            if (idx >= i && ((nums[i] + nums[idx]) <= target)) {
                ans += powerof2[idx - i];
                ans %= mod;
            }
        }

        return ans;
    }



    int binarySearch(vector<int> &nums, int val) {
        
        int l = 0;
        int r = nums.size() - 1;
        int result = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= val) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return result;
    }
};