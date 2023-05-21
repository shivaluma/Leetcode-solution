class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int square = i * i;
            string s = to_string(square);
            if (backtrack(i, s, 1, i)) {
                ans += square;
            }
        }

        return ans;
    }

    bool backtrack(int i , string s, int len, int need) {
        if (s.length() == 0) {
            if (need == 0) {
                return true;
            }
        }

        if (len > s.length()) {
            return false;
        }

        // split current part
        string newS = s.substr(len);
        string removedPart = s.substr(0, len);
        int num = stoi(removedPart);

        bool isEqual1 = backtrack(i, newS, 1, need - num);

        if (isEqual1) {
            return true;
        }


        return backtrack(i, s, len+1, need);
    }
};