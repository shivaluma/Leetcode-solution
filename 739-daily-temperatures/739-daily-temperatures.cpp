class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        
        vector<int> ret(n, 0);
        stack<int> s;
        
        for (int i = 0; i < n; i++) {
            int temp = temperatures[i];
            while (!s.empty()) {
                int colder = s.top();
                if (temp <= temperatures[colder]) {
                    break;
                }
                
                s.pop();
                
                ret[colder] = i - colder;
            }
            
            s.push(i);
        }
        
        return ret;
    }
};