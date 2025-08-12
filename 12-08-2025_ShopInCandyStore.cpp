/*
    In a candy store, there are different types of candies available and prices[i] represent the price of  
    ith types of candies. You are now provided with an attractive offer.
    For every candy you buy from the store, you can get up to k other different candies for free. Find the 
    minimum and maximum amount of money needed to buy all the candies.
    Note: In both cases, you must take the maximum number of free candies possible during each purchase.

    Examples :
    Input: prices[] = [3, 2, 1, 4], k = 2
    Output: [3, 7]
    Explanation: As according to the offer if you buy one candy you can take at most k more for free. So 
    in the first case, you buy the candy worth 1 and takes candies worth 3 and 4 for free, also you need 
    to buy candy worth 2. So min cost: 1+2 = 3. In the second case, you can buy the candy worth 4 and 
    takes candies worth 1 and 2 for free, also you need to buy candy worth 3. So max cost: 3+4 = 7.
*/

class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(),prices.end());
        int min_i=0,min_j=prices.size(),minCandy=0,max_i=prices.size()-1,max_j=-1,maxCandy=0;
        while(min_i < min_j){
            minCandy+=prices[min_i];
            min_j-=k;
            min_i++;
            
            maxCandy+=prices[max_i];
            max_i--;
            max_j+=k;
        }
        return {minCandy,maxCandy};
        
    }
};
