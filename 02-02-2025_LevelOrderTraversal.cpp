/*
    Given a root of a binary tree with n nodes, the task is to find its level order traversal. 
    Level order traversal of a tree is breadth-first traversal for the tree.
*/

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>>ans;
        queue<Node*>q;
        q.push(root);
        ans.push_back({root->data});
        while(!q.empty()){
            vector<int>temp;
            Node* node = q.front();
            q.pop();
            if(node->left) {
                q.push(node->left);
                temp.push_back(node->left->data);
            }
            if(node->right) {
                q.push(node->right);
                temp.push_back(node->right->data);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};