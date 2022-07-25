class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int n = rolls.size();
        
        if (n < k) return 1;
        
        if (k == 1) {
            return n + 1;
        }
        
        unordered_set<int> s;
        
        int count = 0;
        for (int r : rolls) {
            s.insert(r);
            if (s.size() == k) {
                count++;
                s.clear();
            }
        }
        
        return count+1;
    }
};