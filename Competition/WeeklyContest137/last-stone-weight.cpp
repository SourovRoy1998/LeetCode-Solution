//https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p_queue;
        for(auto e: stones)
            p_queue.push(e);
        while(!p_queue.empty()){
            int x=p_queue.top();
            //cout<<x<<" "<<endl;
            p_queue.pop();
            if(p_queue.empty())
                return x;
            int y=p_queue.top();
            p_queue.pop();
            
            if(x!=y)
                p_queue.push(abs(x-y));
        }
            
        return 0;
        
        
    }
};
