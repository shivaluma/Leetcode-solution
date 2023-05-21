class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        if (nums.size() < 3) return false;

        int left = INT_MAX;
        int mid = INT_MAX;

        for (int num : nums) {
            if (num > mid) {
                return true;
            } else if (num > left && num < mid) {
                mid = num;
            } else if (num < left) {
                left = num;
            }
        }

        return false;
    }
};