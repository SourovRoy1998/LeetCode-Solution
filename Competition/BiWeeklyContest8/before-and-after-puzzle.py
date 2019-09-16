##https://leetcode.com/problems/before-and-after-puzzle/

class Solution:
    def beforeAndAfterPuzzles(self, phrases: List[str]) -> List[str]:
        L=[]
        for x in phrases:
            L.append(list(x.split(" ")))
        result=[]
        for i in range(len(L)):
            for j in range(len(L)):
                if(i!=j and L[i][-1]==L[j][0]):
                    temp=L[i][0]
                    for x in L[i][1:]:
                        temp=temp+" "+x 
                    for y in L[j][1:]:
                        temp=temp+" "+y
                    result.append(temp)
        result=list(set(result))
        result.sort()
        return result
                
            
