/*
You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. 
You also have an integer k representing the number of students. The task is to allocate books to each student such 
that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all 
possible allocations, find the arrangement where the student who receives the most pages still has the smallest 
possible maximum.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order 
*/

class Solution {
  public:
    bool isPossible(vector<int> &arr,int k,int mid){
        int sum=0,student=1;
        for(int x:arr){
            sum+=x;
            if(sum>mid){
                student++;
                sum=x;
            }
        }
        return student<=k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k>arr.size())return -1;
        int sum=0,mx=INT_MIN;
        for(int x:arr){
            sum+=x;
            mx=max(mx,x);
        }
        int low=mx,high=sum,mid,ans=INT_MAX;
        while(low<=high){
            mid=(low+high)/2;
            if(isPossible(arr,k,mid)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};