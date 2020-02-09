class Solution {
    public int maxProfit(int[] prices) {
           if(prices.length == 0) return 0;
        int profit = 0;
        int minimum = prices[0];
        
        for(int iter =1 ; iter < prices.length; iter++){
            if(prices[iter] > minimum){
                if(profit < prices[iter] - minimum){
                    profit = prices[iter] - minimum;
                }
            }else if(prices[iter] < minimum){
                minimum = prices[iter];               
            }
        }
        return profit;
    }
}