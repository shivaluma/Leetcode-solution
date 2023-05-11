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
    int getdepth(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        return 1 + max(getdepth(root->left),getdepth(root->right));
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root==NULL)
        {
            return NULL;
        }

        int leftdepth = getdepth(root->left);
        int rightdepth = getdepth(root->right);

        if(leftdepth == rightdepth)
        {
            return root;
        }
        else
        {
            if(leftdepth < rightdepth)
            {
                return subtreeWithAllDeepest(root->right);
            }
            else
            {
                return subtreeWithAllDeepest(root->left);
            }
        }
    }
};