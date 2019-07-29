//https://leetcode.com/problems/stone-game/

//Joke Answer
//return true;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<pair<int,int>>> memoize(n,vector<pair<int,int>>(n,{0,0}));
        for(int l=0;l<n;l++){
            for(int i=0;i+l<n;i++){
                if(l==0) memoize[i][i+l].first=piles[i];
                else{
                    int a=piles[i]+memoize[i+1][i+l].second;
                    int b=piles[i+l]+memoize[i][i+l-1].second;
                    if(a>b){
                        memoize[i][i+l].first=a; memoize[i][i+l].second=memoize[i+1][i+l].first; 
                    }
                    else{ 
                        memoize[i][i+l].first=b; memoize[i][i+l].second=memoize[i][i+l-1].first;
                    }
                }
                
            }
        }
        
        return memoize[0][n-1].first>memoize[0][n-1].second;
    }
};
