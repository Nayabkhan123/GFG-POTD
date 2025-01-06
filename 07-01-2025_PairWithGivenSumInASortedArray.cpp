/*
    You are given an integer target and an array arr[]. You have to find number of pairs in arr[] which sums up 
    to target. It is given that the elements of the arr[] are in sorted order.
    Note: pairs should have elements of distinct indexes. 
*/

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int i=0,j=arr.size()-1,cnt=0;
        while(i<j){
            int pairsum=arr[i]+arr[j];
            if(pairsum<target) i++;
            else if(pairsum>target) j--;
            else{
                cnt++;
                int temp=i+1;
                while(temp<j&&arr[temp]==arr[i]){
                    cnt++;
                    temp++;
                }
                j--;
            }
        }
        return cnt;
    }
};