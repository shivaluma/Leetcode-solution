class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string word1s;
        string word2s;
        
        for (string s : word1) word1s += s;
        for (string s : word2) word2s += s;
        
        return word1s == word2s;
    }
};