class Solution {
public:
     int numFactoredBinaryTrees(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        unordered_map<int, size_t> freq;
        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;
        }
        int res = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++) 
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] == 0 && freq.count(arr[i] / arr[j]))
                {
                    size_t a = (size_t)freq[arr[j]] * (size_t)freq[arr[i] / arr[j]];
                    freq[arr[i]] = (freq[arr[i]] + a) % mod;           
                }
            }
        }
        
        for (auto it : freq) {
            res = (res + it.second) % mod;
        }
        
        return res;
    }
};