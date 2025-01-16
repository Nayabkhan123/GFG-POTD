/*
    Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s 
    and 1s.
*/

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int maxlen=0,sum=0,n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==0) arr[i]=-1;
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0) maxlen=max(maxlen,i+1);
            if(mp.find(sum)==mp.end()) mp[sum]=i;
            if(mp.find(sum)!=mp.end()) maxlen = max(maxlen,i-mp[sum]);
        }
        return maxlen;
    }
};