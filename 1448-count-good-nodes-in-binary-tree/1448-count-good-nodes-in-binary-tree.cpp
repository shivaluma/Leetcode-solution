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
    int goodNodes(TreeNode* root) {
        return count(root, INT_MIN);
    }
    
    int count(TreeNode* root, int maxValue) {
        if (root == NULL) return 0;
        
        
        int countThisNode = root->val >= maxValue ? 1 : 0;
        
        return countThisNode + count(root->left, max(maxValue, root->val)) + count(root->right, max(maxValue, root->val));
    }
};