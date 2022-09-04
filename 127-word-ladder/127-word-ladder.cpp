class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> exist;
        
        int ln = beginWord.length();
        
        unordered_map<string, bool> vis;
        
        for (string s : wordList) {
            exist[s] = true;
        }
    
        
        
        queue<string> q;
        
        q.push(beginWord);
        vis[beginWord] = true;
        int cur = 0;

        while (!q.empty()) {
            cur++;
            int size = q.size();
            while (size--) {
                string s = q.front();
                q.pop();
                
                
            
                if (s == endWord) {
                    return cur;
                }
            
                for (int i = 0; i < s.length(); i++) {
                    for (int j = 0; j < 26; j++) {
                        string scopy = s;
                        scopy[i] = 'a' + j;
                        
                        if (scopy != s && exist[scopy] && !vis[scopy]) {
                            q.push(scopy);
                            vis[scopy] = true;
                        }
                    }
                } 
            }
        }
        
        return 0;
    }
};