/*
    Given a binary tree, convert the binary tree to its Mirror tree.

    Mirror of a Binary Tree T is another Binary Tree M(T) with left and right children of all non-leaf 
    nodes interchanged.     
*/

class Solution {
  public:
    void mirror(Node* node) {
        if(!node) return;
        Node*temp = node->left;
        node->left=node->right;
        node->right=temp;
        mirror(node->left);
        mirror(node->right);
        return;
    }
};