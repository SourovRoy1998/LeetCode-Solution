//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int n=prices.size();
        if(n<2)
            return 0; 
        int sell=prices[n-1];
        
    
        for(int i=n-2;i>=0;i--){
            if(prices[i]<sell)
                maxi=max(maxi,sell-prices[i]);
            else
                sell=prices[i];
        }
        
        return maxi;
    }
};
