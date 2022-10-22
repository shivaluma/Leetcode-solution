class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,int,greater<int>>mp;
        for(auto i : nums) mp[i]++;
        for(auto i : mp) if(mp.count(0-i.first)) return i.first;
        return -1;
    }
};