/*
    Given an array arr[] and an integer target. You have to find numbers of pairs in array arr[] which sums up to 
    given target.
*/

// Optimal Approach
int countPairs(vector<int> &arr, int target) {
    unordered_map<int,int>mp;
    int cnt=0;
    for(int i=0;i<arr.size();i++){
        int rem=target-arr[i];
        if(mp.find(rem)!=mp.end()){
            cnt+=mp[rem];
        }
        mp[arr[i]]++;
    }
    return cnt;
}

// Brute Force Approch (Time Limit Exceeded 1106/1107 Test Cases Passed)
int countPairs(vector<int> &arr, int target) {
    int cnt=0;
    for(int i=0;i<arr.size()-1;i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==target) cnt++;   
        }
    }
    return cnt;
}