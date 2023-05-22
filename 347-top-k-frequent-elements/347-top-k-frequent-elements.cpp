class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> hashmap;
        vector<int> ans;
        priority_queue<int> maxHeap;
        for (auto &num:nums) {
            hashmap[num]++;
        }
        for (auto &it:hashmap) {
            maxHeap.push(it.second);
        }
        while (k>0) {
            int countFreq = maxHeap.top();
            maxHeap.pop();
            for (auto &it:hashmap) {
                if(countFreq == it.second) {
                    ans.push_back(it.first);
                    hashmap.erase(it.first);
                    k--;
                    break;
                }
            }
        }
        return ans;

    }
};