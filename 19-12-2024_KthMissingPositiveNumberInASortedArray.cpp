/*
Given a sorted array of distinct positive integers arr[], we need to find 
the kth positive number that is missing from arr[].  
*/

// binarySearch
class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int s=0;
        int e=arr.size()-1;
        while(s<=e){
            int mid=(s+e)/2;
            int missing=arr[mid]-mid-1;
            if(missing<k){
                s=mid+1;
            }
            else e=mid-1;
        }
        return k + s;
    }
};

//Brute Force Approach
class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int i=0,j=1,cnt=0,element;
        while(true){
            if(arr[i]!=j){
                cnt++;
                element=j;
            }
            else i++;
            if(cnt==k) return element;
            j++;
        }
    }
};