/*
Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.
*/

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int,int>mp;
        int preXor=0,cnt=0;
        for(int i=0;i<arr.size();i++){
            preXor^=arr[i];
            if(preXor==k) cnt++;
            if(mp[preXor^k]) cnt+=mp[preXor^k];
            mp[preXor]++;
        }
        return cnt;
    }
};