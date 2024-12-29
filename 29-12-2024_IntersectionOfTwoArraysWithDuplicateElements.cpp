/*
    Given two integer arrays a[] and b[], you have to find the intersection of the two arrays. 
    Intersection of two arrays is said to be elements that are common in both arrays. The intersection should not
    have duplicate elements and the result should contain items in any order.

    Note: The driver code will sort the resulting array in increasing order before printing.
*/

class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<a.size();i++){
            mp[a[i]]++;
        }
        for(int i=0;i<b.size();i++){
            if(mp[b[i]]){
                mp[b[i]]=0;
                ans.push_back(b[i]);
            }
        }
        return ans;
    }
};