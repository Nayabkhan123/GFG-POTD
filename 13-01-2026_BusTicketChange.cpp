/*
    You are given an array arr[] representing passengers in a queue. Each bus ticket costs 5 coins, 
    and arr[i] denotes the note a passenger uses to pay (which can be 5, 10, or 20). You must serve 
    the passengers in the given order and always provide the correct change so that each passenger 
    effectively pays exactly 5 coins. Your task is to determine whether it is possible to serve all 
    passengers in the queue without ever running out of change.

    Examples:
    Input: arr[] = [5, 5, 5, 10, 20]
    Output: true
    Explanation: From the first 3 customers, we collect three $5 bills in order.
    From the fourth customer, we collect a $10 bill and give back a $5.
    From the fifth customer, we give a $10 bill and a $5 bill.
    Since all customers got correct change we return true.
*/

class Solution {
  public:
    bool canServe(vector<int> &arr) {
        int cnt1=0,cnt2=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==5) cnt1++;
            else if(arr[i]==10){
                if(cnt1==0) return false;
                cnt1--;
                cnt2++;
            }
            else{
                if(cnt2>=1 && cnt1>=1){
                    cnt2--;
                    cnt1--;
                }
                else if(cnt1>=3){
                    cnt1-=3;
                }
                else return false;
            }
        }
        return true;
    }
};