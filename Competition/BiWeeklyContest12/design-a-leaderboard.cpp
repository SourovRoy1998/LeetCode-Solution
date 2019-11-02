//https://leetcode.com/problems/design-a-leaderboard/

class Leaderboard {
public:
    map<int,int> hmap;
    multiset<int> s;
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if(hmap.find(playerId)!=hmap.end()){
            s.erase(s.find(hmap[playerId]));
            hmap[playerId]+=score;
            s.insert(hmap[playerId]);
            
        }
        else{ 
            hmap[playerId]=score;
            s.insert(score);
        }
    }
    
    int top(int K) {
        int sum=0;
        for(auto it=s.rbegin();it!=s.rend();it++){
            sum+=*it;K--;
            if(!K) break;
        }
        return sum;
    }
    
    void reset(int playerId) {
        s.erase(s.find(hmap[playerId]));
        hmap[playerId]=0;
        s.insert(0);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
