class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int maxJump = 0;
        for (int i = 0; i <= maxJump; i++) {
            maxJump = max(maxJump, i + nums[i]);
            if (maxJump >= n - 1) return true;
        }

        return false;
    } 
};