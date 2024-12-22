/*
Given a 2D integer matrix mat[][] of size n x m, where every row and column is sorted in increasing 
order and a number x, the task is to find whether element x is present in the matrix.
*/

// Optimal Approach O(n+m)
bool matSearch(vector<vector<int>> &mat, int x) {
    int i=0,j=mat[0].size()-1;
    while(i<mat.size()&&j>=0){
        if(mat[i][j]==x){
            return true;
        }
        else if (mat[i][j]>x){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}


// Brute Force approch O(n*m)
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==x) return true;
            }
        }
        return false;
    }
};