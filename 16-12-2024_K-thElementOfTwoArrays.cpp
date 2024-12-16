/*
Given two sorted arrays a[] and b[] and an element k, the task is to find the element that
 would be at the kth position of the combined sorted array.
*/

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int i=0,j=0,n=a.size(),m=b.size();
        int ans,cnt=0;
        while(true){
            int x = i<n?a[i]:INT_MAX;
            int y = j<m?b[j]:INT_MAX;
            if(x>y){
                ans=y;
                j++;
            }
            else{
                ans=x;
                i++;
            }
            cnt++;
            if(cnt==k){
                return ans;
            }
            
        }
    }
};