/*
    Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in 
    the subsequence are consecutive integers, the consecutive numbers can be in any order.
*/

class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        int freq[100001]={0};
        int ans=0;
        int cnt=0;
        int maxi=-1;
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
            maxi=max(maxi,arr[i]);
        }
        for(int i=0;i<=maxi;i++){
            if(freq[i]>0){
                cnt++;
            }
            else{
                ans=max(ans,cnt);
                cnt=0;
            }   
        }
        ans=max(ans,cnt);
        return ans;
    }
};

//BruteForce Approach
int longestConsecutive(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    int maxcnt=1,currcnt=1;
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]==arr[i+1]) continue;
        if(arr[i]+1==arr[i+1]){
            currcnt++;
        }
        else currcnt=1;
        maxcnt=max(maxcnt,currcnt);
    }
    return maxcnt;
}