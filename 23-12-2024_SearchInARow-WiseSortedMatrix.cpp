/*
Given a row-wise sorted 2D matrix mat[][] of size n x m and an integer x, find whether element x is present in the matrix.
Note: In a row-wise sorted matrix, each row is sorted in itself, i.e. for any i, j within bounds, mat[i][j] <= mat[i][j+1].
*/


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int n=mat[0].size();
        for(int i=0;i<mat.size();i++){
            if(mat[i][0]<=x&&mat[i][n-1]>=x){
                int s=0,e=mat[0].size()-1;
                while(s<=e){
                    int mid = (s+e)/2;
                    if(mat[i][mid]==x) return true;
                    else if (mat[i][mid]>x){
                        e=mid-1;
                    }
                    else s=mid+1;
                }
            }
            
        }
        return false;
    }
};