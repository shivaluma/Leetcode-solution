class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    
        bool hasOne = false;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) hasOne = true;
            if (nums[i] <= 0 || nums[i] >= nums.size() + 1) {
                nums[i] = 1;
            } 
        }
        
        if (!hasOne) return 1;
        
        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]);
            if (nums[idx-1] > 0) {
                nums[idx-1] = -nums[idx-1];
            }
        }
        
        
        for (int i = 1; i <= nums.size(); i++) {
            if (nums[i-1] > 0) return i;
        }
        
        return nums.size() + 1;
    
    }
};