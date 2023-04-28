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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long int>> q;

        if (root == NULL) return 0;

        if (root->left != NULL) {
            q.push({root->left, 1});
        }

        if (root->right != NULL) {
            q.push({root->right, 2});
        }

        
        long long int ans = 0;

        while(q.size()) {
            
            long long int cur_min = INT_MAX;
            long long int cur_max = INT_MIN;

            int n = q.size();

            long long int k = q.front().second;

            while(n--) {
                cur_min = min(cur_min, q.front().second);
                cur_max = max(cur_max, q.front().second);

                auto& node = q.front();

                

                if (node.first->left) {
                    q.push({node.first->left, (node.second - k)*2 + 1});
                }

                if (node.first->right) {
                    q.push({node.first->right, (node.second - k)*2 + 2});
                }

                q.pop();
            }

            ans = max(ans, cur_max - cur_min);
        }

        return (int)(ans + 1);
    }
};