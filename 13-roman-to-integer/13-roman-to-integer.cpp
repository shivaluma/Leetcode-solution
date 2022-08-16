class Solution {
    int charToInt(char c) {
        if (c == 'I') return 1;
        else if (c == 'V') return 5;
        else if (c == 'X') return 10;
        else if (c == 'L') return 50;
        else if (c == 'C') return 100;
        else if (c == 'D') return 500;
        else return 1000;
    }
public:
    int romanToInt(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int num1 = charToInt(s[i]), num2 = 0;
            if (i + 1 < n)
                num2 = charToInt(s[i + 1]);
            
            if (num1 < num2) {
                ans += (num2 - num1);
                i++;
            }
            else {
                ans += num1;
            }
        }
        return ans;
    }
};