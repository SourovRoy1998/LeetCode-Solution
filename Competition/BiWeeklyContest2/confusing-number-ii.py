## https://leetcode.com/contest/biweekly-contest-2/problems/confusing-number-ii/

def confusingNumberII(self, N: int) -> int:
        hmap=dict()
        hmap['0']='0'
        hmap['1']='1'
        hmap['6']='9'
        hmap['8']='8'
        hmap['9']='6'
        
        confuse=['0','1','6','8','9']
        l=str(N)
        from itertools import product
        chars = confuse
        results = []
        for c in product(chars, repeat = len(l)):
            s=""
            for x in c:
                s+=x
            results.append(s)
        
        count=0
        
        for x in results:
            x=x.lstrip('0')
            if(x!="" and int(x)<=N):
                s=""
                for e in x:
                    s+=hmap[e]
                if(s!=x[::-1]):
                    count+=1
        return count
            
            
