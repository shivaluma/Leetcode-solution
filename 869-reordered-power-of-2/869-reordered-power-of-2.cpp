class Solution {
public:
    bool reorderedPowerOf2(int N) 
    {
        static const set<string> pows {"1", "2", "4", "8", "16", "23", "46", "128", "256", "125", "0124", "0248", "0469", "1289", "13468", "23678", "35566", "011237", "122446", "224588", "0145678", "0122579", "0134449", "0368888", "11266777", "23334455", "01466788", "112234778", "234455668", "012356789", "0112344778"};
        
        string str = to_string(N);
        sort(str.begin(), str.end());
        
        return pows.find(str) != pows.end();
    }
};