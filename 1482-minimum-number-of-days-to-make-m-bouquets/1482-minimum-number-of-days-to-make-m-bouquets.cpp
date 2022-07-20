#define ll long long
class Solution {
public:
    bool check(vector<int>& v, ll m, ll k,ll &mid)
    {
        ll totalBouquets=0,ct=0;
        ll n=v.size();
        for(int i=0;i<n;i++)
        {
          
            if(v[i]<=mid)
            {
                ct++;
                  if(ct==k)
            {
               totalBouquets++;
                ct=0;
            }
            }
            else ct=0;
        }
        if(totalBouquets>=m) return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<m*k)
        {
            return -1;
        }
        ll low=0;
        ll high=INT_MAX-1;
        ll ans=0;
        while(low<=high)
        {
            ll mid=low+(high-low)/2;
            if(check(bloomDay,m,k,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
        
    }
};