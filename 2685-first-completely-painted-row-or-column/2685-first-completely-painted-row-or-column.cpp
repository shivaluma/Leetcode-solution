class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, int> mapbyrow;
        unordered_map<int, int> mapbycol;
        unordered_map<int, pair<int,int>> pos;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pos[mat[i][j]] = {i, j};
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            pair<int,int> position = pos[arr[i]];

            mapbyrow[position.second]++;
            mapbycol[position.first]++;

            if (mapbyrow[position.second] == m || mapbycol[position.first] == n) {
                return i;
            }
        }

        return 0;
    }
};