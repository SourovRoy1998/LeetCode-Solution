//https://leetcode.com/problems/trapping-rain-water/



class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=2) return 0;
        int n=height.size(),result=0;
        vector<int> LeftMost(n);
        vector<int> RightMost(n);
        LeftMost[0]=height[0];
        RightMost[n-1]=height[n-1];
        for(int i=1;i<n;i++)
            LeftMost[i]=max(LeftMost[i-1],height[i]);
        for(int i=n-2;i>=0;i--)
            RightMost[i]=max(RightMost[i+1],height[i]);
        for(int i=1;i<n-1;i++)
            result+=max(0,min(LeftMost[i-1],RightMost[i+1])-height[i]);
        return result;
        
    }
};
