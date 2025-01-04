/*
    Given a sorted array arr[] and a target value, the task is to count triplets (i, j, k) of valid indices, 
    such that arr[i] + arr[j] + arr[k] = target and i < j < k.
*/

class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int n=arr.size(),cnt=0;
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];
                if(sum>target) k--;
                else if(sum<target) j++;
                else if (sum==target){
                    cnt++;
                    int temp=j+1;
                    while(temp<k&&arr[temp]==arr[temp-1]){
                        cnt++;
                        temp++;
                    }
                    k--;
                }
            }
        }
        return cnt;
    }
};