/*
    Given an array arr[] of integers and an integer k, your task is to find the maximum value 
    for each contiguous subarray of size k. The output should be an array of maximum values 
    corresponding to each contiguous subarray.
*/

class Solution {
    public:
      vector<int> maxOfSubarrays(vector<int>& arr, int k) {
          deque<int>dq;
          vector<int>ans;
          for(int i=0;i<arr.size();i++){
              while(!dq.empty() && dq.front()<=i-k) dq.pop_front();
              while(!dq.empty() && arr[i]>=arr[dq.back()]) dq.pop_back();
              dq.push_back(i);
              if(i>=k-1) ans.push_back(arr[dq.front()]);
          }
          return ans;        
      }
  };