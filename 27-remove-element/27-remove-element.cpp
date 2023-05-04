class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
            return 0;
        int left = 0;
        int right = nums.size()-1;
        while (right >= 0 && nums[right] == val)  
            right--;
        
        while (left < right){
            if (nums[left] == val)
                swap(nums[left], nums[right]);           
            while (right > left && nums[right] == val)
                right--;
            left++;                                                       
        }
        if (nums[left] != val)                                    
            left++;    
        return left;
    }
};