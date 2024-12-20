/*
You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array 
while traversing the matrix in spiral form.
*/


class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        int left=0,top=0,bottom=mat.size()-1,right=mat[0].size()-1;
        vector<int>ans;
        while(top<=bottom&&left<=right){
            for(int i=left;i<=right;i++){
                ans.push_back(mat[top][i]);
            }
            top++;
            if(top>bottom) break;
            for(int i=top;i<=bottom;i++){
                ans.push_back(mat[i][right]);
            }
            right--;
            if(right<left) break;
            for(int i=right;i>=left;i--){
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
            if(bottom<top) break;
            for(int i=bottom;i>=top;i--){
                ans.push_back(mat[i][left]);
            }
            left++;
        }
        return ans;
    }
};