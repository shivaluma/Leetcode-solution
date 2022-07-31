class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> uniq;
        
        for (int n : nums) {
            if (n > 0) {
                uniq.insert(n);
            }
            
        }
        
        return uniq.size();
        
    }
};