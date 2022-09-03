/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    //          1 
    //      2        3
    // null null   4   5
    //
    // 1,2,3,#,#,4,5

    
    

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string st = "";
        
        if (root == NULL) return st;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* top = q.front();
            q.pop();
            
            if (top == NULL) {
                st += "#,";
            } else {
                st += to_string(top->val) + ',';          
                q.push(top->left);
                q.push(top->right);
            }

        }
        
       
        return st;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        string temp;
        int value;
        vector<int> nodeValue;

        
        for (char c: data) {
            if (c == '#') {
                nodeValue.push_back(INT_MIN);
                temp = "";
            }
            else if (c == ',') {
                if (temp == "") continue;
                stringstream ss(temp); 
                int num;
                ss >> num;
                nodeValue.push_back(num);
                temp = "";
            } else {
                temp += c;
            }
        }

        if (nodeValue.size() == 0) return NULL;
        
        TreeNode* root = buildTree(nodeValue);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int> &data) {
        int i = 0;
        TreeNode* root = new TreeNode(data[i]);
        i++;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* top = q.front();
            q.pop();
            
            int leftValue = data[i++];
            int rightValue = data[i++];
            
            if (leftValue != INT_MIN) {
                top->left = new TreeNode(leftValue);
                q.push(top->left);
            }
            
            if (rightValue != INT_MIN) {
                top->right = new TreeNode(rightValue);
                q.push(top->right);
            }
        }
                       
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root)); 