/*
    Given a data stream arr[] where integers are read sequentially, the task is to determine the 
    median of the elements encountered so far after each new integer is read.

    There are two cases for median on the basis of data set size.

    1. If the data set has an odd number then the middle one will be consider as median.
    2. If the data set has an even number then there is no distinct middle value and the median 
    will be the arithmetic mean of the two middle values.
*/

class Solution {
    public:
      vector<double> getMedian(vector<int> &arr) {
          priority_queue<int>leftmaxheap;
          priority_queue<int,vector<int>,greater<int>>rightminheap;
          vector<double>ans;
          for(int i=0;i<arr.size();i++){
              leftmaxheap.push(arr[i]);
              
              int ele=leftmaxheap.top();
              rightminheap.push(ele);
              leftmaxheap.pop();
              
              if(rightminheap.size()>leftmaxheap.size()){
                  int ele=rightminheap.top();
                  leftmaxheap.push(ele);
                  rightminheap.pop();
              }
              double median;
              if(leftmaxheap.size()!=rightminheap.size())
              median=leftmaxheap.top();
              else
              median=(double)(leftmaxheap.top()+rightminheap.top())/2;
              ans.push_back(median);
          }
          return ans;
      }
  };