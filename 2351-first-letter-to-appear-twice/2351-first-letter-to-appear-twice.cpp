class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> cc(26, 0);
        
        for (char c : s) {
            cc[c-'a']++;
            if (cc[c-'a'] == 2) return c;
        }
        
        return 'a';
    }
};