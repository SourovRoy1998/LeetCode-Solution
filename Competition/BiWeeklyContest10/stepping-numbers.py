###https://leetcode.com/contest/biweekly-contest-10/problems/stepping-numbers/
class Solution:
    def stepnum(self, A, B):
        
        #while(1):
        #    string=str(A)
        #    ct=0
        #    for i in range(1,len(string)):
        #        if(abs(int(string[i-1])-int(string[i]))!=1):
        #            ct=1
        #    if(ct==0):
        #        break
        
        ans=[]
        final=[0,1,2,3,4,5,6,7,8,9,10]
        
        heapq.heapify(final)
        group=set()
        for i in range(11):
            group.add(i)
        while(1):
            val=heapq.heappop(final)
            if(val>B):
                break
            if(val>=A):
                ans.append(val)
            
            if(str(val)[-1]=='0'):
                if(val*10+1 not in group):
                    heapq.heappush(final,val*10+1)
                    group.add(val*10+1)
            elif(str(val)[-1]=='9'):
                if(val*10-1 not in group):
                    heapq.heappush(final,val*10-1+int(str(val)[-1]))
                    group.add(val*10-1)
            else:
                if(val*10+1 not in group):
                    heapq.heappush(final,val*10+1+int(str(val)[-1]))
                    group.add(val*10+1)
                if(val*10-1 not in group):
                    heapq.heappush(final,val*10-1+int(str(val)[-1]))
                    group.add(val*10-1)
        return ans
    
    
    def countSteppingNumbers(self, low: int, high: int) -> List[int]:
        return self.stepnum(low,high)
