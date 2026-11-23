class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int max_profit = 0;
        // for(int i =0;i<prices.size()-1;i++){
        //     int j =i+1;
        //     while(j<prices.size()){
        //         int profit = prices[j] - prices[i];
        //         max_profit = max(max_profit,profit);
        //         j++;
        // }
        // }
        // return max_profit;
        int minprice =prices[0];
        int maxprofit = 0;
        for(int i = 0;i<prices.size();i++){
            maxprofit = max(maxprofit,prices[i]-minprice);
            minprice = min(minprice,prices[i]);
        }
        return maxprofit;


    }
};
