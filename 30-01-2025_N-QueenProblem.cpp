/*
    The n-queens puzzle is the problem of placing n queens on a (n × n) chessboard such that no two queens 
    can attack each other. Note that two queens attack each other if they are placed on the same row, the 
    same column, or the same diagonal.

    Given an integer n, find all distinct solutions to the n-queens puzzle.
    You can return your answer in any order but each solution should represent a distinct board 
    configuration of the queen placements, where the solutions are represented as permutations 
    of [1, 2, 3, ..., n]. In this representation, the number in the ith position denotes the row 
    in which the queen is placed in the ith column.
    For eg. below figure represents a chessboard [3 1 4 2].
*/

class Solution {
  public:
    void solve(int colo,int n,vector<vector<int>>&ans,vector<int> &sol,vector<bool>&col,vector<bool>&ldiag,vector<bool>&rdiag){
        for(int i=0;i<n;i++){
            if(colo==n){
                ans.push_back(sol);
                return ;
            }
            
            if(!col[i] && !ldiag[colo-i + n-1] && !rdiag[i+colo]){
                sol.push_back(i+1);
                col[i]=true;
                ldiag[colo-i + n-1]=true;
                rdiag[i+colo]=true;
                
                solve(colo+1,n,ans,sol,col,ldiag,rdiag);
                sol.pop_back();
                col[i]=false;
                ldiag[colo-i + n-1]=false;
                rdiag[i+colo]=false;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        vector<bool>col(n,false);
        vector<bool>ldiag(2*n-1,false);
        vector<bool>rdiag(2*n-1,false);
        vector<vector<int>>ans;
        vector<int>sol;
        solve(0,n,ans,sol,col,ldiag,rdiag);
        return ans;
    }
};