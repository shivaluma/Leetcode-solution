class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int start = 0;
        int newStart = start;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans++;
                for (int j = i+1; j < nums.size(); j++) {
                    nums[j] -= nums[i];
                }
                nums[i] = 0;
            }
            else {
                continue;
            }
        }
        
        return ans;
        
    }
};