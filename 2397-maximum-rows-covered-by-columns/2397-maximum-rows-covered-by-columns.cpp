class Solution {
public:
    
    int res = 0;
    
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m = mat.size();
        int n = mat[0].size();
        

        vector<int> vis(n,0);
        
        solve(mat,vis,cols,0);
        
        return res;
        
    }
    
    void solve(vector<vector<int>>& mat, vector<int> &vt, int cols, int cnt) {
        

        if (cols == 0 || cnt == mat[0].size()) {
            int cur = 0;
            for (int i = 0; i < mat.size(); i++) {
                bool good = true;
            
                for (int j = 0; j < mat[i].size(); j++) {
                    if (vt[j] == 0 && mat[i][j] == 1) {
                        good = false;
                        break;
                    }
                }
            
                if (good) {
                    cur++;
                    res = max(cur, res);
                }
            }
            
            return;
        }
        
        vt[cnt] = true;
        solve(mat,vt,cols-1,cnt+1);
        vt[cnt] = false;
        solve(mat,vt,cols,cnt+1);
    }
};