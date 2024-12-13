// A sorted array of distinct elements arr[] is rotated at some unknown point,
// the task is to find the minimum element in it. 

// optimal approch using binary search O(logn)
int findMin(vector<int>& arr) {
        int s=0;
        int e=arr.size()-1;
        
        while(s<e){
            int mid=(s+e)/2;
            if(arr[mid]<=arr[e]){
                e=mid;
            }
            else{
                s=mid+1;
            }
        }
        return arr[s];
    }

// brute force approch linear time complexity
class Solution {
  public:
    int findMin(vector<int>& arr) {
        int min=INT_MAX;
        for(int i=0;i<arr.size();i++){
            if(min>arr[i]) min=arr[i];
        }
        return min;
    }
};