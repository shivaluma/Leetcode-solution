class Solution {
public:
    int arraySign(vector<int>& nums) {
        int current = 1;

        for (int num : nums) {
            if (num == 0) {
                return 0;
            } else if (num < 0 && current < 0) {
                current = 1;
            } else if (num < 0) {
                current = -1;
            }
        }

        return current;
    }
};