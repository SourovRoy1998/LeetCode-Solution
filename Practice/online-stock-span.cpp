//https://leetcode.com/problems/online-stock-span/

class StockSpanner {
public:
    stack<vector<int>> stk;
    StockSpanner() {
    }
    
    int next(int price) {
        int result=1;
        while(!stk.empty() && stk.top()[1]<=price){
            result+=stk.top()[0];
            stk.pop();
            }
        stk.push({result,price});
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
