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
    TreeNode* pruneTree(TreeNode* root) {
        
        int sum = sumFromNode(root);
        
        if (sum == 0) return NULL;
        
        return root;
    }
    
    
    
    int sumFromNode(TreeNode* root) {
        if (root == NULL) return 0;
        
        
        int sumLeft = sumFromNode(root->left);
        if (sumLeft == 0) root->left = NULL;
        
        int sumRight = sumFromNode(root->right);
        if (sumRight == 0) root->right = NULL;
        
        
        return root->val + sumLeft + sumRight;
    }
};