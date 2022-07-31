class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int ans = 0, cur = 1;
        int n = grades.size();
        if (n <= 2) {
            return 1;
        }
        
        while (n >= cur) {
            ans++;
            n -= cur;
            cur++;
        }
        return ans;
        
    }
};