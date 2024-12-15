/*
Given an array arr[] where no two adjacent elements are same, find the index of a peak element. An element is considered 
to be a peak if it is greater than its adjacent elements (if they exist).
If there are multiple peak elements, return index of any one of them. 
The output will be "true" if the index returned by your function is correct; otherwise, it will be "false".

Note: Consider the element before the first element and the element after the last element to be negative infinity.
*/

// O(logn)
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
       if(n==1){
           return 0;
       }
       
       int lo=0, hi=n-1;
       while(lo<=hi){
           int mid=lo+(hi-lo)/2;
           if(mid==0 && arr[mid]>=arr[mid+1]){
               return 0;
           }
           else if(mid==n-1 && arr[mid]>=arr[mid-1]){
               return n-1;
           }
           else if(arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1]){
               return mid;
           }
           else{
               if(mid>0 && arr[mid-1]>arr[mid]){
                   hi=mid-1;
               }
               else{
                   lo=mid+1;
               }
           }
       }
    }
};
// Brute Force Approach O(n)
int peakElement(vector<int> &arr) {
    int n=arr.size();
    if(n==1) return 0;
    for(int i=0;i<n;i++){
        if(i-1<0){
            if(arr[i]>arr[i+1]) return i;
        }
        else if(i+1>=n){
            if(arr[i]>arr[i-1]) return i;
        }
        else{
            if(arr[i]>arr[i+1]&&arr[i]>arr[i-1]) return i;
        }
    }
    return -1;
}