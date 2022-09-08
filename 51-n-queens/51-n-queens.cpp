class Solution {
public:
    
    // For each row of the matrix, put a queen in any index of that row -> move to next row
    // Put a new queen, check if that queen if conflict with any other queen, if yes, return and backtrack.
    // if row == n, return the matrix.
    
    vector<vector<string>> ans;
    
    
    bool isSafe(vector<string> &curr, int r, int c) {
        // check row
        for(char &letter : curr.at(r))
            if(letter == 'Q') return false;

        // check the upper left diagonal
        for(int i = r, j = c; i >= 0 && j >= 0; i--,j--) {
            string word = curr.at(i);
            if(word.at(j) == 'Q') return false;
        }
        
        // check the lower left diagonal
        for(int i = r, j = c; i < curr.size() && j >= 0; i++, j--) {
            string word = curr.at(i);
            if(word.at(j) == 'Q') return false;
        }
        
        return true;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        string s(n, '.');        
        vector<string> curr(n, s);
        
        backtrack(curr, 0, n);
        
        return ans;
    }
    
    
    void backtrack(vector<string> &current, int col, int n) {
        if (col == n) {
            ans.push_back(current);
        }
        
        for (int i = 0; i < n; i++) {
            if (isSafe(current, i, col)) {
                current[i][col] = 'Q';
                backtrack(current, col+1, n);
                current[i][col] = '.';
            }
        }
    
        
    }
};