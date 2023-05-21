class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        string result = "";
 
    
        for (int i = 0; i < s1.length() || i < s2.length(); i++) { 
            if (i < s1.length()) 
                result += s1[i];
            if (i < s2.length()) 
                result += s2[i];
        } 
        
        return result; 
    }
};