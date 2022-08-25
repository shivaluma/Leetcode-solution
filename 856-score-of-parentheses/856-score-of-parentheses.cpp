class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        

        int streak = 0;
    
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            if (c == '(') {
                streak++;
            }
            
            if (c == ')') {
                streak--;
                if (s[i-1] == '(') {
                    ans += 1 << streak;
                }
            }
        }
        
        return ans;
    }
};