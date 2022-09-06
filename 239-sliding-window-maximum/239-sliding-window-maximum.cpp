class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        deque< int > dq;
        
        int i=0;
        
        vector<int> res;
        
        while(i<n)
        {
            if(i>=k)
            res.push_back(nums[dq.front()]);
            
            while(!dq.empty() && i-k >= dq.front() )
            {
                dq.pop_front();
            }
            
             while(!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            i++;
            
        }
        
        res.push_back(nums[dq.front()]);
        
        return res;
        
    }
};