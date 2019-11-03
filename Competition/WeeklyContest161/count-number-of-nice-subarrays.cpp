//https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int m) {
        int n=a.size();
        int count = 0; 
        int prefix[n] = { 0 }; 
        int odd = 0; 
  
        // traverse in the array 
        for (int i = 0; i < n; i++)  
        { 
  
            prefix[odd]++; 
  
            // if array element is odd 
            if (a[i] & 1) 
               odd++; 
  
            // when number of odd elements>=M 
           if (odd >= m) 
               count += prefix[odd - m];
        }
        
        return count;
    }
};
