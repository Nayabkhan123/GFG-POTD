/*
    Given a binary tree, the diameter (also known as the width) is defined as the number of edges on the 
    longest path between two leaf nodes in the tree. This path may or may not pass through the root. 
    Your task is to find the diameter of the tree.
*/

class Solution {
  public:
    int recursion(Node* root,int &ans){
        if(!root) return 0;
        int LH = recursion(root->left,ans);
        int RH = recursion(root->right,ans);
        ans=max(ans,LH+RH);
        return max(LH,RH)+1;
        
    }
    int diameter(Node* root) {
        int ans=0;
        recursion(root,ans);
        return ans;
    }
};