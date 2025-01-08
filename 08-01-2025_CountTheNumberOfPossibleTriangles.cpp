/*
    Given an integer array arr[]. Find the number of triangles that can be formed with three different array 
    elements as lengths of three sides of the triangle. 

    A triangle with three given sides is only possible if sum of any two sides is always greater than the 
    third side.
*/

class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size(),cnt=0;
        for(int i=n-1;i>1;i--){
            int j=0,k=i-1;
            while(j<k){
                if(arr[j]+arr[k]>arr[i]){
                    cnt+=k-j;
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return cnt;
    }
};