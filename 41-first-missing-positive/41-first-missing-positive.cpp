class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //step 1
        bool one =false;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1) one=true;
            if(nums[i]<1 || nums[i]>n)
                nums[i]=1;
            
        }
        
        if(one==false)return 1;
        
        //step 2;
        for(int i=0;i<n;i++)
        {
            int index=abs(nums[i]);
            if(nums[index-1]>0)
                nums[index-1]=-1*nums[index-1];
        }
        
        //step 3;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)return i+1;
        }
        return n+1;
    }
};