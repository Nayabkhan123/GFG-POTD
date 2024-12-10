class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        int count = 0;
        sort(intervals.begin(),intervals.end());
        int prev = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<prev){
                count++;
                prev = min(prev,intervals[i][1]);
            }
            else{
                prev = intervals[i][1];
            }
        }
        return count;
    }
};
