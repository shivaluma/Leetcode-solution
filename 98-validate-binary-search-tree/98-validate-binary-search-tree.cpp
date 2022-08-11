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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, (long long)INT_MIN-5, (long long)INT_MAX+5);
    }
    
    bool isValidBST(TreeNode* root, long long min, long long max) {
        if (root == NULL) return true;
        
        if ((long long)root->val >= max) return false;
        if ((long long)root->val <= min) return false;
        
        return isValidBST(root->left, min, (long long)root->val) && isValidBST(root->right, (long long)root->val, max);
    } 
};