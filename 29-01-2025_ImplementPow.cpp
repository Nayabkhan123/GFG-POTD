/*
    Implement the function power(b, e), which calculates b raised to the power of e (i.e. be).
*/

class Solution {
  public:
    double power(double b, int e) {
        if(e==0) return 1;
        if(e<0) return 1/power(b,-e);
        double tempans = power(b,e/2);
        if(e%2==0){
            return tempans*tempans;
        }
        else{
            return tempans*tempans*b;
        }
    }
};