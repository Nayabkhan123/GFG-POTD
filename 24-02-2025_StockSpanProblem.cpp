/*
    The stock span problem is a financial problem where we have a series of daily price 
    quotes for a stock and we need to calculate the span of stock price for all days. 
    The span arr[i] of the stocks price on a given day i is defined as the maximum 
    number of consecutive days just before the given day, for which the price of the 
    stock on the given day is less than or equal to its price on the current day.
*/

class Solution {
    public:
      vector<int> calculateSpan(vector<int>& arr) {
          stack<int>st;
          int n = arr.size();
          vector<int>ans(n);
          for(int i=0;i<n;i++){
              while(!st.empty() && arr[st.top()] <= arr[i]){
                  st.pop();
              }
              if(st.empty()) ans[i]=i+1;
              else ans[i]=i-st.top();
              st.push(i);
          }
          return ans;
      }
  };