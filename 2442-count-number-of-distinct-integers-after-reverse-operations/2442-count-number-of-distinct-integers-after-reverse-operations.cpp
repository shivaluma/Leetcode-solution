class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> dist(nums.begin(), nums.end());
        
        for (int num : nums) {
            int rev = 0;
            while (num) {
                rev *= 10;
                rev += num%10;
                num /= 10;
            }
            
            dist.insert(rev);
        }
        
        return dist.size();
    }
};