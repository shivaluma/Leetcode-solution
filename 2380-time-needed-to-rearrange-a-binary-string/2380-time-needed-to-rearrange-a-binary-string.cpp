class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        bool isZeroOnePairExist = true;
        
        int ans = 0;
        while (isZeroOnePairExist) {
            isZeroOnePairExist = false;
            for (int i = 0; i < s.length() - 1; i++) {
                if (s[i] == '0' && s[i+1] == '1') {
                    s[i] = '1'; 
                    s[i+1] = '0';
                    isZeroOnePairExist = true;
                    i++;
                }
            }
            
            ans++;
        }
        
        return ans-1;
    }
};