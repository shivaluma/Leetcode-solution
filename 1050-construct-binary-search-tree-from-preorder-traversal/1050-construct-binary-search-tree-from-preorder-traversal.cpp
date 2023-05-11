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
    vector<int> preorder;
    int n;

    TreeNode* helper(int lower, int upper) {
        // if all elements from preorder are used
        // then the tree is constructed
        if (idx == n) return nullptr;

        int val = preorder[idx];
        // if the current element 
        // couldn't be placed here to meet BST requirements
        if (val < lower || val > upper) return nullptr;

        // place the current element
        // and recursively construct subtrees
        idx++;
        TreeNode* root = new TreeNode(val);
        root->left = helper(lower, val);
        root->right = helper(val, upper);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        this->preorder = preorder;
        n = preorder.size();
        return helper(INT_MIN, INT_MAX);
    }
};