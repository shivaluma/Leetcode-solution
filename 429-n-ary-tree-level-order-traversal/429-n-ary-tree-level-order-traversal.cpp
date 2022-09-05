/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        
        vector<vector<int>> res;
        
        if (!root) return res;
        
        queue<Node*> q;

        

        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> currentLevel(size);
            int idx = 0;
            while (size--) {
                Node* front = q.front();
                q.pop();
            
                
                if (!front) continue;
                
                currentLevel[idx++] = front->val;
                
                for (Node* node:front->children) {
                    q.push(node);
                }
            }
            
            res.push_back(currentLevel);
        }
        
        return res;
    }
};