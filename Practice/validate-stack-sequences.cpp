//https://leetcode.com/problems/validate-stack-sequences/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i=0;
        for(auto x:pushed){
            if(i>=popped.size()) return false;
            stk.push(x);
            while(!stk.empty() && stk.top()==popped[i]){
                i++;
                stk.pop();
            }
        }
        
        return stk.empty();
    }
};
