// brute force (testcase passed 1110 /1111)
class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int x=0;
        int y=0;
        for(int i=0;i<a.size();i++){
            if(a[i]>b[0]){
                int temp=a[i];
                a[i]=b[0];
                b[0]=temp;
                sort(b.begin(),b.end());
                
            }
        }
    }
};
// optimal approch 
void mergeArrays(vector<int>& a, vector<int>& b) {
        int i=a.size()-1;
        int j=0;
        while(i>=0&&j<b.size()){
            if(a[i]<b[j]) break;
            else{
                swap(a[i],b[j]);
                i--;
                j++;
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
    }