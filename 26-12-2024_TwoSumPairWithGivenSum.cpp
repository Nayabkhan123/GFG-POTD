/*
    Given an array arr[] of positive integers and another integer target. Determine if there exists two distinct 
    indices such that the sum of there elements is equals to target.
*/

// Optimal Approach
bool twoSum(vector<int>& arr, int target) {
    sort(arr.begin(),arr.end());
    int i=0,j=arr.size()-1;
    while(i<j){
        if(arr[i]+arr[j]==target) return true;
        else if (arr[i]+arr[j]>target) j--;
        else i++;
    }
    return false;
}

// Better Approch
bool twoSum(vector<int>& arr, int target) {
    unordered_map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        int rest=target-arr[i];
        if(mp.find(rest)!=mp.end()){
            return true;
        }
        mp[arr[i]]==i;
    }
    return false;
}

//Brute Force Approach
bool twoSum(vector<int>& arr, int target) {
    for(int i=0;i<arr.size()-1;i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==target) return true;
        }
    }
    return false;
}
