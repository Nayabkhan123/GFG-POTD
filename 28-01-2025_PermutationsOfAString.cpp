/*
    Given a string s, which may contain duplicate characters, your task is to generate and return an 
    array of all unique permutations of the string. You can return your answer in any order.
*/

class Solution {
  public:
    void solve(int i,int n,string s,string permu,unordered_set<string>&st){
        if(permu.size()==n){
            st.insert(permu);
            return;
        }
        for(int j=i;j<n;j++){
            swap(s[i],s[j]);
            permu.push_back(s[i]);
            solve(i+1,n,s,permu,st);
            permu.pop_back();
            swap(s[i],s[j]);
        }
    }
    vector<string> findPermutation(string &s) {
        unordered_set<string>st;
        int n=s.size();
        string permu;
        solve(0,n,s,permu,st);
        vector<string>ans(st.begin(),st.end());
        return ans;
    }
};