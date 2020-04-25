#include <climits>

class Solution {
public:
    
    bool strictLocalMin(vector<int>& prices, int i){
        
        if (i + 1 >= prices.size()) return false; // don't buy on last day
        
        int left = INT_MAX;
        
        if (i > 0)
            left = prices[i - 1];
        
        return (prices[i] <= left) && (prices[i] <= prices[i + 1]);
    }
    
    bool strictLocalMax(vector<int>& prices, int i){
        
        int left = INT_MIN;
        int right = INT_MIN;
        
        if (i > 0)
            left = prices[i - 1];
        
        if (i + 1 < prices.size())
            right = prices[i + 1];
        
        return (prices[i] >= left) && (prices[i] >= right);
    }
    
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() < 2) return 0;
        
        bool bought = false;
        int buyPrice = 0;
        int profit = 0;
        
        for (int i = 0; i < prices.size(); i++){
            if (!bought){
                if (strictLocalMin(prices, i)){
                    bought = true;
                    buyPrice = prices[i];
                }
            }
            else {
                if (strictLocalMax(prices, i)){
                    bought = false;
                    profit += (prices[i] - buyPrice);
                }
            }
        }
        
        
        return profit;
    }
};
