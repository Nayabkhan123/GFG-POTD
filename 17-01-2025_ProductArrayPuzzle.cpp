/*
    Given an array, arr[] construct a product array, res[] where each element in res[i] is the product of all 
    elements in arr[] except arr[i]. Return this resultant array, res[].
    Note: Each element is res[] lies inside the 32-bit integer range.
*/

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int product=1,zerocnt=0;
        vector<int>res;
        for(auto it:arr) {
            if(it==0) zerocnt++;
            else product*=it;
        }
        
        if(zerocnt==0) {
            for(auto it :arr) res.push_back(product/it);
        }
        else if (zerocnt==1){
            for(auto it :arr){
                if(it==0) res.push_back(product);
                else res.push_back(0);
            }
        }
        else{
            for(auto it :arr) res.push_back(0);
        }
        return res;
    }
};