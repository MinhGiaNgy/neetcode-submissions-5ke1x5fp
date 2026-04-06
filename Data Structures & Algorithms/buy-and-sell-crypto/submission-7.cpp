// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int l{0};
//         int r{0};
//         int max_profit{-1};
//         int profit{-1};
//         if(prices.size() > 0){
//             r = 1;
//         }
//         while(r < prices.size()){
//             if(prices[l] < prices[r]){
//                 profit = prices[r] - prices[l];
//                 max_profit = max(profit, max_profit);
//             } else {
//                 l = r;
//             } 
//             r++;
//         }
//         if(max_profit < 0){
//             return 0;
//         }
//         return max_profit;
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit{-1};
        int min_selling_price = prices[0];

        for(auto day : prices){
            max_profit = max(max_profit, day - min_selling_price);
            min_selling_price = min(day, min_selling_price);
        }
        if(max_profit < 0){
            return 0;
        }
        return max_profit;
    }
};