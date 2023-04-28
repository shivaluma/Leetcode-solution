class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_from_here = 0;
        int max_so_far = nums[0];

        for (int num : nums) {
            max_from_here = max(max_from_here + num, num);
            max_so_far = max(max_so_far, max_from_here);
        }

        return max_so_far;
    }
};