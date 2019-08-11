//https://leetcode.com/problems/swap-for-maximum-repeated-substring/



class Solution {
public:
    int maxRepOpt1(string text) {
        if(text.size()<=1) return text.size();
        int n=text.size(), result=1;
        map<char,int> hmap;
        for(auto x : text){
            hmap[x]++;
        }
        vector<int> forward(n,1);
        vector<int> backward(n,1);
        for(int i=1;i<n;i++)
            if(text[i]==text[i-1]){
                forward[i]=forward[i-1]+1;
                result=max(result,forward[i]);
            }
        for(int i=n-2;i>=0;i--)
            if(text[i]==text[i+1])
                backward[i]=backward[i+1]+1;
        for(int i=1;i<n-1;i++){
            if(text[i-1]==text[i+1]){
                if(hmap[text[i-1]]>forward[i-1]+backward[i+1])
                    result=max(forward[i-1]+backward[i+1]+1,result);
                else
                    result=max(result, forward[i-1]+backward[i+1]);
            }
            else if(hmap[text[i-1]]>forward[i-1])
                result=max(result,forward[i-1]+1);
        }
        
        return result;
        
        
    }
};
