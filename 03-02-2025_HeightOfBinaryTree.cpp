/*
    Given a binary tree, find its height.
    The height of a tree is defined as the number of edges on the longest path from the root to a leaf node. 
    A leaf node is a node that does not have any children.
*/

class Solution {
  public:
    int recursion(Node* node){
        if(!node){
            return -1;
        }
        return max(recursion(node->left),recursion(node->right)) + 1;
    }
    int height(Node* node) {
        return recursion(node);
    }
};