/*
    Given an array arr[] containing only non-negative integers, your task is to find a continuous subarray 
    (a contiguous sequence of elements) whose sum equals a specified value target. You need to return the 
    1-based indices of the leftmost and rightmost elements of this subarray. You need to find the first 
    subarray whose sum is equal to the target.

    Note: If no such array is possible then, return [-1].
*/

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int sum=0,s=0,e=0,n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>target){
                while(s<e && sum>target){
                    sum-=arr[s];
                    s++;
                }
            }
            if (sum==target) return {s+1,e+1};
            e++;
        }
        return {-1};
    }
};