/*
    Given a binary tree and an integer k, determine the number of downward-only paths where the sum 
    of the node values in the path equals k. A path can start and end at any node within the tree 
    but must always move downward (from parent to child).
*/

class Solution {
    public:
      void recursion(Node*root,int &count,int currsum,unordered_map<int,int>&mp,int k){
          if(!root) return;
          currsum+=root->data;
          if(currsum==k) count++;
          if(mp.find(currsum-k)!=mp.end()){
              count+=mp[currsum-k];
          }
          mp[currsum]++;
          recursion(root->left,count,currsum,mp,k);
          recursion(root->right,count,currsum,mp,k);
          mp[currsum]--;
      }
      int sumK(Node *root, int k) {
          unordered_map<int,int>mp;
          int count = 0;
          recursion(root,count,0,mp,k);
          return count;
      }
};