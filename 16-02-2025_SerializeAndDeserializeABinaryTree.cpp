/*
    Serialization is to store a tree in an array so that it can be later restored and deserialization 
    is reading tree back from the array. Complete the functions

    serialize() : stores the tree into an array a and returns the array.
    deSerialize() : deserializes the array to the tree and returns the root of the tree.
    Note: Multiple nodes can have the same data and the node values are always positive integers. 
    Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same 
    as the input tree. Driver code will print the in-order traversal of the tree returned by 
    deSerialize(serialize(input_tree)).
*/

class Solution {
    public:
      vector<int>pre;
      int i=0;
      void preorder(Node* root,vector<int>& pre){
          if(!root) {
              pre.push_back(-1);
              return;
          }
          pre.push_back(root->data);
          preorder(root->left,pre);
          preorder(root->right,pre);
      }
      vector<int> serialize(Node *root) {
          preorder(root,pre);
          return pre;
      }
      Node *deSerialize(vector<int> &arr) {
          int val = arr[i++];
          if(val==-1){
              return NULL;
          }
          Node* newNode = new Node(val);
          newNode->left = deSerialize(arr);
          newNode->right = deSerialize(arr);
          return newNode;
      }
  };