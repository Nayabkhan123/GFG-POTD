/*
Given a sorted and rotated array arr[] of distinct elements, 
the task is to find the index of a target key.
 Return -1 if the key is not found.
*/

// using binary search O(logn)
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int s=0,e=arr.size()-1,mid=-1;
        while(s<=e){
            mid = (s+e)/2;
            if(arr[mid]==key) return mid;
            else if(arr[mid]>=arr[s]){
                if(arr[mid]>key&&arr[s]<=key) e=mid-1;
                else s=mid+1;
            }
            else{
                if(arr[mid]<key&&arr[e]>=key) s=mid+1;
                else e=mid-1;
            }
        }
        
        return -1;
    }
};
//linear search O(n)
int search(vector<int>& arr, int key) {
    for(int i=0;i<arr.size();i++){
        if(arr[i]==key) return i;
    }
    return -1;
}