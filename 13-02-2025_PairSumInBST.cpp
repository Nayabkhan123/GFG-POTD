/*
    Given a Binary Search Tree(BST) and a target. Check whether there's a pair of Nodes in 
    the BST with value summing up to the target. 
*/

class Solution {
    public:
      bool searchPair(Node* root,Node* curr,int k){
          if(!root) return false;
          if(k==root->data && curr!=root){
              return true;
          }
          if(k<root->data) {
              return searchPair(root->left,curr,k);   
          }
          return searchPair(root->right,curr,k);  
      }
      bool solve(Node* root,Node* curr,int target){
          if(!curr) return false;
          if(searchPair(root,curr,target- curr->data)){
              return true;
          }
          return solve(root,curr->left,target) || solve(root,curr->right,target);
      }
      bool findTarget(Node *root, int target) {
          if(!root) return false;
          return solve(root,root,target);
      }
  };

class Solution {
    public:
      bool findSum(Node* root,set<int> &s,int& target){
          if(!root) return false;
          if(s.find(target-root->data)!=s.end()) return true;
          s.insert(root->data);
          return findSum(root->left,s,target) || findSum(root->right,s,target);
      }
      bool findTarget(Node *root, int target) {
          set<int>s;
          return findSum(root,s,target);
      }
  };

class Solution {
    public:
      void inorder(Node* root,vector<int> &ans){
          if(!root) return ;
          inorder(root->left,ans);
          ans.push_back(root->data);
          inorder(root->right,ans);
      }
      bool findTarget(Node *root, int target) {
          vector<int>ans;
          inorder(root,ans);
          int i=0,j=ans.size()-1;
          while(i<j){
              int sum = ans[i]+ans[j];
              if(sum == target) return true;
              else if (sum>target) j--;
              else i++;
          }
          return false;
      }
  };