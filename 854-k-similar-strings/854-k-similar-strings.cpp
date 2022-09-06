// class Solution {
// public:
//     int ans = INT_MAX;
//     int kSimilarity(string s1, string s2) {
        
//         solve(s1,s2,0,0);
        
//         return ans;
//     }
    
//     void solve(string &s1, string &s2, int i, int step) {
        
//         if (step > ans) return;
        
//         if (i == s1.length()) {
//             ans = min(ans, step);
//             return;
//         }
        
//         if (s1[i] == s2[i]) {
//             solve(s1,s2,i+1, step);
//             return;
//         }
        
        
//         for (int j = i+1;j < s1.length(); j++) {
//             if (s1[i] == s2[j]) {
//                 swap(s2[i], s2[j]);
//                 solve(s1,s2,i+1,step+1);
//                 swap(s2[i], s2[j]);
//             }
//         }
//     }
// };



class Solution {
public:
    int ans = INT_MAX;
    void dfs(string &s1 , string &s2 , int i , int count)
    {
        //cout << s1 << ',' << s2 << ',' << i << ',' << count << '\n';
       
        if (s1 == s2)
        {
            ans = min(count , ans);
            return;
        }
            
        
        if (s1[i] == s2[i])
        {
           dfs(s1 , s2 , i + 1 , count );
        }
        else        
        {
            for (int j = i + 1 ; j < s1.size() ; j ++)
            {
                if (s1[j] == s2[i] && s1[i] != s2[i] && s1[j] != s2[j] && s1[i] == s2[j])
                {
                    swap(s1[i] , s1[j]);
                    dfs(s1 , s2 , i + 1 , count + 1 );
                    swap(s1[i] , s1[j]);
                    return;
                }
            }
            
            for (int j = i + 1 ; j < s1.size() ; j ++)
            {
                if (s1[j] == s2[i] && s1[i] != s2[i] && s1[j] != s2[j])
                {
                    swap(s1[i] , s1[j]);
                    dfs(s1 , s2 , i + 1 , count + 1 );
                    swap(s1[i] , s1[j]);
                }
            }
        }
        
        
            
    }
    
    
    
    int kSimilarity(string s1, string s2) {
        vector<int> min_count(22 , INT_MAX);
        unordered_set<string> k;
        dfs(s1 , s2 , 0 , 0);
        return ans;
    }
};