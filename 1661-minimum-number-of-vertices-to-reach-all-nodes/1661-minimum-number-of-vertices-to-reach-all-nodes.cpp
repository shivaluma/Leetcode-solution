class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool>  incoming(n, false);

        for (auto& e : edges) {
            incoming[e[1]] = true;
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!incoming[i]) {
                ans.emplace_back(i);
            }
        }

        return ans;
    }
};