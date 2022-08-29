char x = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int count = 0; 
        for (int i = 0;i < grid.size();i++) {
            for (int j = 0; j < grid[i].size();j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    
    void bfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size()) return;
        if (j < 0 || j >= grid[0].size()) return;
        if (grid[i][j] == '0') return;
        grid[i][j] = '0';
        bfs(grid,i+1,j);
        bfs(grid,i-1,j);
        bfs(grid,i,j+1);
        bfs(grid,i,j-1);
    }
    
    
};