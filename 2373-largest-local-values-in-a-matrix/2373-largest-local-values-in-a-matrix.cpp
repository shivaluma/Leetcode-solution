class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        int row = 0;
        int col = 0;
        
        vector<vector<int>> ans(n-2, vector<int>(n-2, 0));
        for (int i = 0; i < n - 2; i++) {
            for (int o = 0; o < n-2; o++) {
                
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        ans[i][o] = max(grid[i+j][k+o], ans[i][o]);
                    }
                }
            }
        }
        
        return ans;
    }
};