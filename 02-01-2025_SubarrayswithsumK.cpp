/*
    Given an unsorted array of integers, find the number of continuous subarrays having sum exactly equal to a 
    given number k.
*/

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        int ans=0,sum=0;
        unordered_map<int,int>mp;
        for(auto x : arr){
            sum+=x;
            if(sum==k) ans++;
            ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};