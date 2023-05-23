class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_idx = 0;
        int t_idx = 0;

        while (s_idx < s.length() && t_idx < t.length()) {
            if (s[s_idx] == t[t_idx]) {
                s_idx++;
                t_idx++;
            }
            else t_idx++;
        }

        return s_idx == s.length();
    }
};