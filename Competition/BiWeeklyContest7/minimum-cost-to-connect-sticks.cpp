//https://leetcode.com/contest/biweekly-contest-7/problems/minimum-cost-to-connect-sticks/


class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int result=0,first,second;
        for(auto x : sticks)
            pq.push(x);
        while(!pq.empty()){
            first=pq.top();pq.pop();
            if(pq.empty()) break;
            second=pq.top();pq.pop();;
            result+=(first+second);
            pq.push(first+second);
        }
        return result;
    }
};
