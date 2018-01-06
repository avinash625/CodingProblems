class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int Cprofit = 0;
        for(int iter = 0, size = prices.size(); iter < size -1; iter++){
            if(prices[iter] < prices[iter+1]){
                Cprofit = prices[iter+1] - prices[iter];
                if(Cprofit  > 0)
                    profit += Cprofit;
            }
        }
        return profit;
    }
};
