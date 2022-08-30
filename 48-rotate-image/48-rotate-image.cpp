class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int i = 0;i<n/2;i++) {
            for (int j = i;j<n-i-1;j++) {
                
                int val = matrix[i][j];
     
                int nextRow = i;
                int nextCol = j;
                for (int k = 0; k <= 3; k++) {
                    int tmpRow = nextRow;
                    nextRow = nextCol;
                    nextCol = n - tmpRow - 1;
                    
                    int temp = matrix[nextRow][nextCol];

                    matrix[nextRow][nextCol] = val;
                    val = temp;
                }
            }
        }
    }
};