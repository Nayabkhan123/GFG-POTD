/*
    Given two arrays representing the inorder and preorder traversals of a binary tree, construct the tree 
    and return the root node of the constructed tree.

    Note: The output is written in postorder traversal.
*/

class Solution {
  public:
    unordered_map<int,int>mp;
    Node* solve(vector<int>&preorder,int s,int e,int &preind){
        if(s>e) return NULL;
          
        int val=preorder[preind];
        Node* root = new Node(preorder[preind++]);
        root->left=solve(preorder,s,mp[val]-1,preind);
        root->right=solve(preorder,mp[val]+1,e,preind);
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        int preind=0;
        return solve(preorder,0,inorder.size()-1,preind);
    }
};