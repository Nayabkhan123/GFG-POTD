/*
    Given a binary tree, the task is to find the maximum path sum. The path may start and end 
    at any node in the tree.
*/

class Solution {
    public:
      int recursion(Node* root,int &ans){
          if(!root) return 0;
          int left = recursion(root->left,ans);
          left=max(0,left);
          int right = recursion(root->right,ans);
          right=max(0,right);
          ans = max(ans,left+right+root->data);
          return max(left,right) + root->data;
      }
      int findMaxSum(Node *root) {
          int ans=INT_MIN;
          recursion(root,ans);
          return ans;
      }
  };