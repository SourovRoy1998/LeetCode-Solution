//https://leetcode.com/contest/biweekly-contest-9/problems/minimum-time-to-build-blocks/

class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        priority_queue<int> pq;
        for(int b:blocks)pq.push(-b);
        while(pq.size()>1){
            int a=-pq.top();
            pq.pop();
            int b=-pq.top();
            pq.pop();
            pq.push(-(split+max(a,b)));
        }
        return -pq.top();
    }
};


/*
class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split)
    {
        priority_queue<int> queue;
        for (int b : blocks)
            queue.push(-b);
        while (queue.size() > 1) {
            int t1 = queue.top(); queue.pop();
            int t2 = queue.top(); queue.pop();
            int t = std::min(t1, t2) - split;
            queue.push(t);
        }
        return -queue.top();
    }
};
*/
