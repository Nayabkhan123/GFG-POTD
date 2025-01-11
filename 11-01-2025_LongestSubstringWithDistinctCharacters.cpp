/*
    Given a string s, find the length of the longest substring with all distinct characters. 
*/


class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        vector<int>vis(26,0);
        int maxi=INT_MIN;
        int i=0,j=0;
        while(j<s.size()){
            while(vis[s[j]-'a']>0){
                vis[s[i]-'a']=0;
                i++;
            }
            vis[s[j]-'a']++;
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};