class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int i = m-1, j = n-1, end = m + n - 1;
        
        while (i >= 0 && j >= 0)
            a[end--] = a[i]>b[j] ? a[i--] : b[j--];

        while (j >= 0)
            a[end--] = b[j--];
    }
};