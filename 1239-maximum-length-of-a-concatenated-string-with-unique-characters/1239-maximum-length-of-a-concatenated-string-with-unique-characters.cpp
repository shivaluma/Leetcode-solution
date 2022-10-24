class Solution {
public:
    
    int maxl = 0;
    int maxLength(vector<string>& arr) {
        
        vector<int> freq(26,0);
        
        backtrack(arr, 0, freq, "");
        
        return maxl;
    }
    
    
    void backtrack(vector<string> &arr, int idx, vector<int> &freq, string curword) {
            // pick tis word
        
            if (idx >= arr.size()) return;
        
            string originalWord = curword;
        
            bool conflict = false;
            for (char c : arr[idx]) {
                freq[c-'a']++;
                if (freq[c-'a'] >= 2) {
                    conflict = true;
                }
            }
            
            if (!conflict) {
                curword += arr[idx];
                maxl = max(maxl, (int)curword.length());
                backtrack(arr, idx+1, freq, curword);
            }
            
            
            
            // unpick this word
            for (char c : arr[idx]) {
                freq[c-'a']--;
            }
        
            backtrack(arr, idx+1, freq, originalWord);
    }
    
    
};