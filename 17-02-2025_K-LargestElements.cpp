/*
    Given an array arr[] of positive integers and an integer k, Your task is to return k largest 
    elements in decreasing order. 
*/

class Solution {
    public:
      vector<int> kLargest(vector<int>& arr, int k) {
          priority_queue<int>pq;
          for(auto it:arr){
              pq.push(it);
          }
          vector<int>ans;
          while(k--){
              ans.push_back(pq.top());
              pq.pop();
          }
          return ans;
      }
  };