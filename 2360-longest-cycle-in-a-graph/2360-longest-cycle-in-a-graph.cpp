class Solution {
public:


    int ans = -1;
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        
        vector<int> step(n, -1); // -1 mean no processing.
        for (int i = 0; i < n; i++) {
            dfs(edges, step, i, 1);
        }
        
        return ans;
        
    }
    
    
    void dfs(vector<int>& edges, vector<int>& step, int v, int stepNum) {
        if (v > -1) {
            if (step[v] == -1) {
                step[v] = stepNum;
                dfs(edges, step, edges[v], stepNum + 1);
            }
            else if (step[v] > 0) {
                ans = max(ans, stepNum - step[v]);
            }
            
            step[v] = 0;

        } 
    }
    
    
    
};