/*
    Given an array arr[] of n sorted linked lists of different sizes. The task is to merge 
    them in such a way that after merging they will be a single sorted linked list, then 
    return the head of the merged linked list.
*/

class Solution {
    public:
      Node* mergeKLists(vector<Node*>& arr) {
          priority_queue<int,vector<int>,greater<int>>pq;
          for (auto it : arr){
              while(it){
                  pq.push(it->data);
                  it=it->next;
              }
          }
          Node* ans = new Node(pq.top());
          pq.pop();
          Node* temp1 = ans;
          while(!pq.empty()){
              int data = pq.top();
              pq.pop();
              Node* temp2 = new Node(data);
              temp1->next = temp2;
              temp1=temp2;
          }
          return ans;
      }
  };