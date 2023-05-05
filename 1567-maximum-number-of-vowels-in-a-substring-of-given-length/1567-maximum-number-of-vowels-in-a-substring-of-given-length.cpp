class Solution {
public:

    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int ans = 0;

        int current_vowels = 0;

        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                current_vowels++;
            }
        }

        ans = current_vowels;

        for (int i = k; i < s.length(); i++) {
            if (isVowel(s[i-k])) {
                current_vowels--;
            }

            if (isVowel(s[i])) {
                current_vowels++;
            }

            ans = max(ans, current_vowels);
        }

        return ans;
    }
};