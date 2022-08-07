class Solution {
public:
    int countVowelPermutation(int n) {
        vector<char> vowel{'0', 'a', 'e', 'i', 'o', 'u'};
//         unordered_map<char, int> prev;
        
//         prev['a'] = 3;
//         prev['e'] = 2;
//         prev['i'] = 2;
//         prev['o'] = 1;
//         prev['u'] = 2;
        
        unordered_map<char,vector<int>> next_char;
        
        next_char['a'] = {2};
        next_char['e'] = {1,3};
        next_char['i'] = {1, 2, 4, 5};
        next_char['o'] = {3, 5};
        next_char['u'] = {1};
        
        
        vector<vector<long long>> dp(n+1, vector<long long>(6, 1));
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= 5; j++) {
                
                dp[i][j] = 0;
                for (int c : next_char[vowel[j]]) {
                    dp[i][j] += (dp[i-1][c]%(long long)(1e9+7));
                }
                
            }
        }
        
        
        long long ans = 0;
        for (int i = 1; i <= 5; i++) {
            ans += dp[n][i] % (int)(1e9+7);
        }
        
        return ans % (int)(1e9+7);
    }
};