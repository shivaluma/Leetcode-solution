class Solution {
public:
   
        
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0 ) {
                int j = i;
                while (j < nums.size() && nums[j] == 0) {
                    j++;
                }
                
                long long length = j - i;
                i = j - 1;
                res += length*(length + 1)/2;
            }
        }
        
        
        return res;
    }
};