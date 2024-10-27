/*
    Leetcode: 121. Best Time to Buy and Sell Stock
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int i = 0, j = 1;
        while(j < prices.size()){
            if( prices[j] < prices[i]){
                i++;
            }
            else{
                profit = max(profit, prices[j] - prices[i]);
                j++;
            }
        }
        return profit;
    }
};
