//https://leetcode.com/problems/find-k-pairs-with-smallest-sums/



class Solution {
public:
    struct Cell{
        int num1,num2,index;
        Cell(int x,int y,int z){num1=x;num2=y;index=z;}
        
        bool operator<(const Cell& rhs)const {
            return num1+num2>rhs.num1+rhs.num2;
        }
    };
    
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        priority_queue<Cell> pq;
        int m=nums1.size(),n=nums2.size();
        if(m*n==0) return {};
        for(int i=0;i<min(k,m);i++)
            pq.push({nums1[i],nums2[0],0});
        while(!pq.empty() && k--){
            auto elem=pq.top();pq.pop();
            result.push_back({elem.num1,elem.num2});
            if(elem.index==n-1) continue;
            pq.push({elem.num1,nums2[elem.index+1],elem.index+1});
        }
        return result;
    }
};
