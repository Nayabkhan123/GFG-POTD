/*
    Given a string s consisting of opening and closing parenthesis '(' and ')'. Find the length of 
    the longest valid parenthesis substring.

    A parenthesis string is valid if:

    For every opening parenthesis, there is a closing parenthesis.
    The closing parenthesis must be after its opening parenthesis.
*/

class Solution {
    public:
      int maxLength(string& s) {
          stack<int>st;
          st.push(-1);
          int maxi=0;
          for(int i=0;i<s.size();i++){
              if(s[i]=='(') st.push(i);
              else{
                  st.pop();
                  if(!st.empty()) maxi=max(maxi,i-st.top());
                  else st.push(i);
              }
          }
          return maxi;
      }
  };