/*
    Given an array arr[] containing integers and an integer k, your task is to find the length of the longest 
    subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum 
    equal to k, return 0.
*/

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        int maxlen=0,sum=0,n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k){
                maxlen=max(maxlen,i+1);
            }
            if(mp.find(sum)==mp.end()) mp[sum]=i;
            if(mp.find(sum-k)!=mp.end()) maxlen=max(maxlen,i-mp[sum-k]);
        }
        return maxlen;
    }
};