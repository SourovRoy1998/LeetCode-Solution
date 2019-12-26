###https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/

from collections import defaultdict
class Solution:
    def findSpecialInteger(self, arr):
        d=defaultdict(int)
        for x in arr:
            d[x]+=1
            if d[x]>(len(arr)/4):
                return x
            
            
 '''
 for(int i=0;i<n/2;i++){
            if(first_major==arr[i])
                first_count++;
            else
                first_count--;
            if(first_count<0){
                first_count=1;
                first_major=arr[i];
            }
                
        }
'''
