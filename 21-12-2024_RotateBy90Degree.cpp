/*
Given a square matrix mat[][] of size n x n. The task is to rotate it by 90 degrees in an anti-clockwise 
direction without using any extra space. 
*/
// without using extra space
class Solution {
  public:
    void rotateby90(vector<vector<int>>& mat) {
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i=0;i<n/2;i++){
            swap(mat[i],mat[n-i-1]);
        }
    }
};
// using extra space
void rotateby90(vector<vector<int>>& mat) {
    int n=mat.size();
    vector<vector<int>>ans(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j]=mat[j][n-i-1];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=ans[i][j];
        }
    }
}