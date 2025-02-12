/*
    Given a BST and an integer k, the task is to find the kth smallest element in the BST. 
    If there is no kth smallest element present then return -1.
*/
class Solution {
    public:
      void inorder(Node* root,int& k,int& ans){
          if(!root) return;
          inorder(root->left,k,ans);
          k--;
          if(k==0){
              ans=root->data;
              return;
          }
          inorder(root->right,k,ans);
      }
      int kthSmallest(Node *root, int k) {
          int ans=-1;
          inorder(root,k,ans);
          return ans;
      }
  };


class Solution {
    public:
      void inorder(Node* root,vector<int>&ans){
          if(!root) return;
          inorder(root->left,ans);
          ans.push_back(root->data);
          inorder(root->right,ans);
      }
      int kthSmallest(Node *root, int k) {
          vector<int>ans;
          inorder(root,ans);
          return ans.size()>=k ? ans[k-1] : -1;
      }
  };