##https://leetcode.com/problems/occurrences-after-bigram/

class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        L=list(text.strip().split(" "))
        n=len(L)
        Ans=[]
        for i in range(n-2):
            if(L[i]==first and L[i+1]==second):
                Ans.append(L[i+2])
        return Ans
        
