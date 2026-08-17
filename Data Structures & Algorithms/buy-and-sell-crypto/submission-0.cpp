class Solution {
public:
    int maxProfit(vector<int>& prices) {
            // forgotten edge cases which i dont submit in this 
        if (prices.empty()) {
            return 0;
        }
         
    // start in this part     
        int min_prices = prices[0]; // first set min = first element
        int max_profit =0;
        
        for(int i=1;i<prices.size();i++){
            if(prices[i] < min_prices){
                min_prices = prices[i];
            }
            int today_profit = prices[i]- min_prices;
            if(today_profit > max_profit){
                max_profit = today_profit;
            }
        }
        return max_profit;
    }
};
