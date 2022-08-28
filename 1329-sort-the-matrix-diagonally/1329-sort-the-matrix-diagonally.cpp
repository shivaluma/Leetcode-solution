class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        unordered_map<int, vector<int>> diagonal;
        
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                for (int k = 0;;k++) {
                    
                    if (i + k >= n || j + k >= m) break;
                    diagonal[i*1000 + j].push_back(mat[i+k][j+k]);
                }

                sort(diagonal[i*1000 + j].begin(), diagonal[i*1000 + j].end());
            }
        }
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 && j >= 0) || (i >= 0 && j == 0)) {
                    for (int k = 0;;k++) {
                        if (i + k >= n || j + k >= m) break;
                        mat[i+k][j+k] = diagonal[i*1000 + j][k];  
                }
                }
            }
        }
        
        
        return mat;
    }
};