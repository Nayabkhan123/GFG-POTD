/*
    Given an array arr[] with non-negative integers representing the height of blocks. If the width of each 
    block is 1, compute how much water can be trapped between the blocks during the rainy season. 
*/

// timeComplexity -> O(N) spaceComplexity -> O(1)
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n=arr.size(),lftmax=0,rgtmax=0,i=0,j=n-1,totalwater=0;
        while(i<j){
            lftmax=max(lftmax,arr[i]);
            rgtmax=max(rgtmax,arr[j]);
            if(arr[i]<=arr[j]){
                totalwater+=lftmax-arr[i];
                i++;
            }
            else{
                totalwater+=rgtmax-arr[j];
                j--;
            }
        }
        return totalwater;
    }
};

// timeComplexity -> O(N) spaceComplexity -> O(N)
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n=arr.size(),maxwater=0;
        vector<int>lftmax(n,0),rgtmax(n,0);
        lftmax[0]=arr[0];
        rgtmax[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            lftmax[i]=max(lftmax[i-1],arr[i]);
            rgtmax[n-i-1]=max(rgtmax[n-i],arr[n-i-1]);
        }
        for(int i=0;i<n;i++){
            maxwater+=min(lftmax[i],rgtmax[i])-arr[i];
        }
        return maxwater;
    }
};