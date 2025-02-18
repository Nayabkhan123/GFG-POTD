/*
    Given an array of points where each point is represented as points[i] = [xi, yi] on the X-Y plane 
    and an integer k, return the k closest points to the origin (0, 0).

    The distance between two points on the X-Y plane is the Euclidean distance, defined as: 

    sqrt( (x2 - x1)2 + (y2 - y1)2 )

    Note: You can return the k closest points in any order, driver code will sort them before printing.
*/

class Solution {
    public:
      vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
          priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>pq;
          for(auto it:points){
              int dis = sqrt((it[0]*it[0]) + (it[1]*it[1]));
              pq.push({dis,it});
          }
          vector<vector<int>>ans;
          while(k--){
              ans.push_back(pq.top().second);
              pq.pop();
          }
          return ans;
      }
  };