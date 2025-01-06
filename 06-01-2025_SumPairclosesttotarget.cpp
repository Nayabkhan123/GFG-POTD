/*
    Given an array arr[] and a number target, find a pair of elements (a, b) in arr[], where a<=b whose sum is 
    closest to target.
    Note: Return the pair in sorted order and if there are multiple such pairs return the pair with maximum 
    absolute difference. If no such pair exists return an empty array.
*/

class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int i=0,j=arr.size()-1;
        int diff=INT_MAX;
        vector<int>ans;
        while(i<j){
            int pairsum=arr[i]+arr[j];
            if(abs(target-pairsum)<diff){
                diff=abs(target-pairsum);
                ans={arr[i],arr[j]};
            }
            if(pairsum>target) j--;
            else if(pairsum<target) i++;
            else return ans;
        }
        return ans;
    }
};