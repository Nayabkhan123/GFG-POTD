/*
    Given a Binary Tree, your task is to return its In-Order Traversal.

    An inorder traversal first visits the left child (including its entire subtree), then visits the node, 
    and finally visits the right child (including its entire subtree).
*/

class Solution {
  public:
    vector<int> inorder(Node* root,vector<int>&ans){
        if(!root) return ans;
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
        return ans;
    }
    vector<int> inOrder(Node* root) {
        vector<int>ans;
        return inorder(root,ans);
    }
};