/*
    Given an array arr[] and an integer target. You have to find the number of pairs in the array whose sum is 
    strictly less than the target.
*/

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        sort(arr.begin(),arr.end());
        int cnt=0;
        int i=0,j=arr.size()-1;
        while(i<j){
            if(arr[i]+arr[j]<target){ 
                cnt+=(j-i);
                i++;
            }
            else j--;
        }
        return cnt;
    }
};
