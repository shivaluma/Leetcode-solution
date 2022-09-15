class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        sort(a.begin(), a.end());
        unordered_map<int,int> map;
        vector<int> ans;
        for (int num : a) {
            map[num]++;
        }
        
        for (int num: a) {
            
            if (map[num] <= 0) {
                continue;
            }
            
            map[num]--;
            map[num*2]--;
            
            if (map[num] < 0 || map[num*2] < 0) {
                return {};
            }
            
            ans.push_back(num);
        }
        
        return ans;
    }
};