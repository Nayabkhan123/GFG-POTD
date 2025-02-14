/*
    Given the root of a Binary search tree(BST), where exactly two nodes were swapped by mistake. 
    Your task is to fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
    Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. 
    All changes must be reflected in the original Binary search tree(BST).
*/

class Solution {
    public:
      Node* first,*second,*temp,*prev;
      void inorder(Node* root){
          if(!root) return;
          inorder(root->left);
          if(prev && root->data < prev->data){
              if(!first){
                  first = prev;
                  temp = root;
              }
              else{
                  second = root;   
              }
          }
          prev = root;
          inorder(root->right);
      }
      void correctBST(Node* root) {
          first=second=temp=prev=NULL;
          inorder(root);
          if(first&&second){
              swap(first->data,second->data);
          }
          else if(first && !second){
              swap(first->data,temp->data);
          }
      }
  };

// Brute Force Approach
class Solution {
    public:
      void inorder(Node* root,vector<int>&temp,bool flag){
          if(!root) return;
          inorder(root->left,temp,flag);
          if(flag){
              temp.push_back(root->data);
          }
          else{
              root->data=temp.back();
              temp.pop_back();
          }
          inorder(root->right,temp,flag);
      }
      void correctBST(Node* root) {
          vector<int>temp;
          inorder(root,temp,true);
          sort(temp.begin(),temp.end(),greater<int>());
          inorder(root,temp,false);
      }
  };
  