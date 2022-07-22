#define ll long long
class Solution {
public:
    ll minSumSquareDiff(vector<int>& n1, vector<int>& n2, int k1, int k2) {
      unordered_map<ll, ll>mp;
      ll nops = 0;
      ll sum = 0;
      for(int i=0; i<n1.size(); i++)
        mp[abs(n1[i] - n2[i])]++;
      ll top = 0;
      for(auto it=mp.begin(); it!=mp.end(); it++)
        top = max(top, it->first);
      while(nops < k1+k2 and top > 0){
        if(mp[top]){
          ll currOps = (mp[top] + nops <= k1+k2)?mp[top]:(k1+k2)-nops;
          mp[top] -= currOps;
          mp[top-1] += currOps;
          nops += currOps;         
        }
        top--;
      }
      for(auto [x, y]:mp)
        sum += x*x*y;
      return sum;
    }
};