class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
};


class Solution {
public:
    vector<string> ans;
    int row, col;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        row = board.size();
        col = board[0].size();
        
        TrieNode* root = new TrieNode();
        
        
        // Adding words to Trie
        for (string word : words) {
            TrieNode* start = root;
            for (int i = 0; i < word.length(); i++) {
            
                if (start->children[word[i]-'a'] != NULL) {
                    start = start->children[word[i]-'a'];
                    
                } else {
                    start->children[word[i]-'a'] = new TrieNode();
                    start = start->children[word[i]-'a'];
                }
                
                bool isEnd = i == word.length() - 1;
                if (isEnd) start->isEnd = true;
            }
        }
        
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                dfs(board, root, i, j, "");
            }
        }
        
        
        return ans;
        
        
        
    }
    
    
    void dfs(vector<vector<char>>& board, TrieNode* root, int i, int j, string curword) {
        if (i >= row || j >= col || i < 0 || j < 0 || board[i][j] == '#') return;
        

        TrieNode* ptr = root->children[board[i][j]-'a'];
        if (ptr) {
            char ch = board[i][j];
            curword += ch;
            
            if (ptr->isEnd) {
                ans.push_back(curword);
                ptr->isEnd = false;
            }
            
            board[i][j] = '#';
            dfs(board, ptr,i+1,j,curword);
            dfs(board, ptr,i,j+1,curword);
            dfs(board, ptr,i-1,j,curword);
            dfs(board, ptr,i,j-1,curword);
            board[i][j] = ch;
        }
    }
    
};