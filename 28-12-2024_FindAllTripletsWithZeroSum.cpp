/*
    Given an array arr[], find all possible triplets i, j, k in the arr[] whose sum of elements is equals to zero.
    Returned triplet should also be internally sorted i.e. i<j<k.
*/

class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        vector<vector<int>>ans;
        int n=arr.size();
        for(int i=0;i<n-2;i++){
            unordered_map<int,vector<int>>mp;
            for(int j=i+1;j<n;j++){
                int rem=0-arr[i]-arr[j];
                if(mp.count(rem)){
                    for(auto k:mp[rem]){
                        ans.push_back({i,k,j});
                    }
                }
                mp[arr[j]].push_back(j);
            }
        }
        return ans;
    }
};

// O(n^3)
vector<vector<int>> findTriplets(vector<int> &arr) {
    vector<vector<int>>v;
    for(int i=0;i<arr.size()-2;i++){
        for(int j=i+1;j<arr.size()-1;j++){
            for(int k=j+1;k<arr.size();k++){
                if(arr[i]+arr[j]+arr[k]==0) v.push_back({i,j,k});
            }
        }
    }
    return v;
}
