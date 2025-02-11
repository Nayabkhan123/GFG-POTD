/*
    Given the root of a binary tree. Check whether it is a BST or not.
    Note: We are considering that BSTs can not contain duplicate Nodes.
    A BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
*/

class Solution {
    public:
      void inorder(Node* root, vector<int>&temp){
          if(!root) return;
          inorder(root->left,temp);
          temp.push_back(root->data);
          inorder(root->right,temp);
      }
      bool isBST(Node* root) {
          vector<int>temp;
          inorder(root,temp);
          for(int i=0;i<temp.size()-1;i++){
              if(temp[i]>temp[i+1]) return false;
          }
          return true;
      }
  };
  