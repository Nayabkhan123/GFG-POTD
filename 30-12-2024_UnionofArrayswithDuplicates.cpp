/*
    Given two arrays a[] and b[], the task is to find the number of elements in the union between these two arrays.

    The Union of the two arrays can be defined as the set containing distinct elements from both arrays. If there 
    are repetitions, then only one element occurrence should be there in the union.

    Note: Elements of a[] and b[] are not necessarily distinct.
*/

// using map
class Solution {
  public:
    int findUnion(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        unordered_map<int,int>mp;
        long long cnt=0;
        for(int i=0;i<n;i++){
            if(mp[a[i]]){
                continue;
            }
            mp[a[i]]++;
            cnt++;
        }
        for(int i=0;i<m;i++){
            if(mp[b[i]]){
                continue;
            }
            mp[b[i]]++;
            cnt++;
        }
        return cnt;
    }
};

// using set
int findUnion(vector<int>& a, vector<int>& b) {
    unordered_set<int>s;
    for(auto it:a) s.insert(it);
    for(auto it:b) s.insert(it);
    return s.size();
}