class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);


        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (dfs(graph, color, i, 0)) {
                    return 0;
                }
            }
        }

        return 1;
    }


    bool dfs(vector<vector<int>> &graph, vector<int> &colors, int u, int color) {
        if (colors[u] != -1) {
            if (colors[u] == color) return 0;
            else return 1;
        }

        colors[u] = color;

        for (auto& v : graph[u]) {
            if (dfs(graph, colors, v, color ^ 1)) {
                return 1;
            }
        }

        return 0;
    }
};