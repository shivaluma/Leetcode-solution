class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int res = 0;
        
        char first = suits[0];
        int count = 0;
        
        for (char c : suits) {
            if (first == c) {
                count++;
            }
        }
        
        if (count == 5) return "Flush";
        
        count = 0;
        

        for (int i : ranks) {
            int temp = 0;
            for (int j : ranks) {
                if (i == j) {
                    temp++;
                }
            }
            
            count = max(temp, count);
        }
        
        if (count >= 3) {
            return "Three of a Kind";
        }
        else if (count == 2) {
            return "Pair";
        }
        
        return "High Card";
    }
};