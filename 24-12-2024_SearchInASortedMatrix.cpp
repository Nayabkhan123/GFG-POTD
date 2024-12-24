/*
    Given a strictly sorted 2D matrix mat[][] of size n x m and a number x. 
    Find whether the number x is present in the matrix or not.
    Note: In a strictly sorted matrix, each row is sorted in strictly increasing order, 
    and the first element of the ith row (i!=0) is greater than the last element of the (i-1)th row.
*/

bool searchMatrix(vector<vector<int>> &mat, int x) {
    int n=mat.size();
    int m=mat[0].size();
    int s=0,e=(n*m)-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(mat[mid/m][mid%m]==x) return true;
        else if (mat[mid/m][mid%m]<x) s=mid+1;
        else e=mid-1;
    }
    return false;
}


class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr.push_back(mat[i][j]);
            }
        }
        int s=0,e=arr.size()-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]==x) return true;
            else if (arr[mid]<x) s=mid+1;
            else e=mid-1;
        }
        return false;
    }
};