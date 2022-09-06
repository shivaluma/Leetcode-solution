class Solution {
public:
    int ans = INT_MAX;
    int kSimilarity(string s1, string s2) {
        
        solve(s1,s2,0,0);
        
        return ans;
    }
    
    void solve(string &s1, string &s2, int i, int step) {
        
        if (step > ans) return;
        
        if (i == s1.length()) {
            ans = min(ans, step);
            return;
        }
        
        if (s1[i] == s2[i]) {
            solve(s1,s2,i+1, step);
            return;
        }
        
        
        for (int j = i+1;j < s1.length(); j++) {
            if (s1[i] == s2[j]) {
                swap(s2[i], s2[j]);
                solve(s1,s2,i+1,step+1);
                swap(s2[i], s2[j]);
            }
        }
    }
};