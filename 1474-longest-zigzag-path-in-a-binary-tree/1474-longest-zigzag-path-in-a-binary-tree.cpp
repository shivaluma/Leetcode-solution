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
    int max_score = 0;
    int longestZigZag(TreeNode* root) {
        dfs(root, 0, true);
        dfs(root, 0, false);

        return max_score;
    }

    void dfs(TreeNode* root, int current_score, bool require_left) {
        if (root == NULL) {
            return;
        }

        max_score = max(max_score, current_score);
        
        if (require_left) {
            dfs(root->left, current_score+1, false);
            dfs(root->right, 1, true);
        } else {
            dfs(root->right, current_score+1, true);
            dfs(root->left, 1, false);
        }

    }
}; 