/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10, 0);
        
        if (root == NULL) return 0;
        
        solve(root, freq);
        
        return ans;
        
    }
    
    void solve(TreeNode* root, vector<int> &freq) {
        freq[root->val]++;
        if (root->left) {
            solve(root->left, freq);
        }
        
        if (root->right) {
            solve(root->right, freq);
        }
        
        
        if (root->left == NULL && root->right == NULL) {
            int oddCount = 0;
            for (int num : freq) {
                oddCount += num % 2;
            }
            
            if (oddCount <= 1) {
                ans++;
            }
        }
        
        freq[root->val]--;
    }
};