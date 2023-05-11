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
    int idx = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;

        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }


        return build(preorder, m, 0, preorder.size() - 1);
    }

    TreeNode* build(vector<int> &preorder, unordered_map<int, int> &m, int l, int r) {

        if (l > r) {
            return NULL;
        }

        if (idx >= preorder.size()) {
            return NULL;
        }

        int i = m[preorder[idx]];

        if (i < l || i > r) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[idx++]);

        root->left = build(preorder, m, l, i);
        root->right = build(preorder, m, i+1, r);

        return root;
    }
};