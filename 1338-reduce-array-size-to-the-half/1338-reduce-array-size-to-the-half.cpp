class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> count;
        
        for (int a : arr) {
            count[a]++;
        }
        
        priority_queue<pair<int, int>> priorityq;
        
        for (auto &a : count) {
            priorityq.push(make_pair(a.second, a.first));
        }
        
        int half_size = int(ceil(arr.size() / 2.0));
        
        int curr = 0;
        int ans = 0;
        while (curr < half_size) {
            auto top = priorityq.top();
            priorityq.pop();
            curr += top.first;
            ans++;
        }
        
        return ans;
    }
};