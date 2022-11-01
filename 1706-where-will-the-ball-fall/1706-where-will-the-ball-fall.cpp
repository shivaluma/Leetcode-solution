class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int b = grid[0].size();
        int row = grid.size();
        vector<int> ans(b, 0);
        for (int i = 0; i < b; i++) {
            int pos = i;
            for (int j = 0; j < row; j++) {
                if (pos == 0 && grid[j][pos] == -1) {
                    pos = -1;
                    break;
                }
                else if (pos == b-1 && grid[j][pos] == 1) {
                    pos = -1;
                    break;
                }
                else if (pos < b-1 && grid[j][pos] == 1 && grid[j][pos+1] == -1) {
                    pos = -1;
                    break;
                }
                else if (pos > 0 && grid[j][pos] == -1 && grid[j][pos-1] == 1) {
                    pos = -1;
                    break;
                }
                
                else {
                    pos += grid[j][pos];
                }
            }
            ans[i] = pos;
        }
        
        return ans;
    }
};