/*
    Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']', 
    verify the validity of the arrangement.
    An input string is valid if:

            1. Open brackets must be closed by the same type of brackets.
            2. Open brackets must be closed in the correct order.
*/

class Solution {
    public:
      bool isBalanced(string& s) {
          stack<char>st;
          for(auto it : s){
              if(it == '(' || it == '[' || it == '{' ){
                  st.push(it);
              }
              else{
                  if(!st.empty() && ((it == ')' && st.top() == '(') || 
                      (it == '}' && st.top() == '{') || (it == ']' && st.top() == '['))){
                      st.pop();
                  }
                  else{
                      return false;
                  }
              }
          }
          return st.empty();
      }
  };