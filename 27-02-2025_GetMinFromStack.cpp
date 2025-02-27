/*
    Given q queries, You task is to implement the following four functions for a stack:

    push(x) – Insert an integer x onto the stack.
    pop() – Remove the top element from the stack.
    peek() - Return the top element from the stack. If the stack is empty, return -1.
    getMin() – Retrieve the minimum element from the stack in O(1) time. If the stack is empty, return -1.
    Each query can be one of the following:

    1 x : Push x onto the stack.
    2 : Pop the top element from the stack.
    3: Return the top element from the stack. If the stack is empty, return -1.
    4: Return the minimum element from the stack.
*/

class Solution {
    public:
      vector<int>arr;
      int mini=INT_MAX;
      Solution() {
          
      }
      // Add an element to the top of Stack
      void push(int x) {
          if(arr.size()==0) mini=x;
          else if(mini>=x){
              arr.push_back(mini);
              mini=x;
          }
          arr.push_back(x);
      }
      // Remove the top element from the Stack
      void pop() {
          if(arr.size()==0){
              return;
          }
          else{
              int temp = arr.back();
              arr.pop_back();
              if(mini==temp && arr.size()!=0){
                  mini=arr.back();
                  arr.pop_back();
              }
          }
      }
      // Returns top element of the Stack
      int peek() {
          if(arr.size()==0) return -1;
          return arr.back();
      }
      // Finds minimum element of Stack
      int getMin() {
          if(arr.size()==0) return -1;
          return mini;
      }
  };