class Solution {
public:
    vector<int> ans;
    vector<int> numsSameConsecDiff(int n, int k) {
        
        for (int i = 1; i <= 9; i++) {
            solve(i, k, n-1, i);
        }
        
        return ans;
    }
    
    void solve(int &num, int k, int n, int last) {
        
        if (n <= 0) {
            ans.push_back(num);
            return;
        }
        
        int top = last + k;
        int bottom = last - k;
        
        
        if (top <= 9) {
            int next = num*10 + top;
            solve(next, k, n-1, top);
        }
        
        if (bottom >= 0 && top != bottom) {
            int next = num*10 + bottom;
            solve(next, k, n-1, bottom);
        }
    }
};