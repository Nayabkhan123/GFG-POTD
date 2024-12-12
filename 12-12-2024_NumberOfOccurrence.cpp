// brute force approch timeComplexity=O(n)
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int cnt = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==target) cnt++;
        }
        return cnt;
    }
};
// optimal approch using binarySearch timeComplexity=O(logn)
int countFreq(vector<int>& arr, int target) {
        int s=0,e=arr.size()-1;
        int firstindex=-1,lastindex=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]==target){
                firstindex=mid;
                e=mid-1;
            }
            else if(arr[mid]>target) e=mid-1;
            else s=mid+1;
        }
        s=0;
        e=arr.size()-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]==target){
                lastindex=mid;
                s=mid+1;
            }
            else if(arr[mid]>target) e=mid-1;
            else s=mid+1;
        }
        if(firstindex==-1&&lastindex==-1) return 0;
        return lastindex-firstindex+1;
    }