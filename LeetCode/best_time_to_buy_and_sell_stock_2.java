class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length == 0) return 0;
        int totalProfit = 0;
        int buy_price = prices[0];
        for(int current_price : prices){
            if(current_price > buy_price){
                totalProfit += (current_price - buy_price);
                buy_price = current_price;
            }else{
                buy_price = current_price;
            }
        }
        return totalProfit;
    }
}