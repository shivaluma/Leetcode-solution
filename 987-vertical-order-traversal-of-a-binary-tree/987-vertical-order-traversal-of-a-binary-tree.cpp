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
private:
    void dfs(TreeNode *root,map<pair<int,int>,multiset<int>>&m,int row,int col){
       if(!root) return;
       m[{col,row}].insert(root->val);
       if(root->left)
          dfs(root->left,m,row+1,col-1);
       if(root->right)
          dfs(root->right,m,row+1,col+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root){
       map<pair<int,int>,multiset<int>> m;
       dfs(root,m,0,0);
       vector<vector<int>> v;
       map<int,vector<int>> map;
       for(auto&_m:m)
          for(auto&__m:_m.second)
             map[_m.first.first].push_back(__m);
       for(auto&_map:map)
          v.push_back(_map.second);
       return v;
    }
};