class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBPrice = INT_MAX;
        int profit = 0;
        for(int iter = 0,size = prices.size(); iter< size;iter++){
            if(prices[iter] < minBPrice){
                minBPrice = prices[iter];
            }
            if(profit  < (prices[iter] - minBPrice)){
                profit = prices[iter] - minBPrice;
            }
        }
        return profit;
    }
};
