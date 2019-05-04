//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        int maxi=0;
        int temp_high=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            maxi=max(maxi,temp_high-prices[i]);
            temp_high=max(temp_high,prices[i]);
        }  
        return maxi;
        
    }
};
