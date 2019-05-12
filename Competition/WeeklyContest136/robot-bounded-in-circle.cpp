//https://leetcode.com/problems/robot-bounded-in-circle/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        char current='N';
        int x=0;
        int y=0;
        for(auto p: instructions){
            if(p=='L'){
                if(current=='N')
                    current='W';
                else if(current=='W')
                    current='S';
                else if(current=='S')
                    current='E';
                else if(current=='E')
                    current='N';     
            }
            
            else if(p=='R'){
                if(current=='N')
                    current='E';
                else if(current=='W')
                    current='N';
                else if(current=='S')
                    current='W';
                else if(current=='E')
                    current='S';     
            }
            
            else{
                if(current=='N')
                    y++;
                else if(current=='S')
                    y--;
                else if(current=='E')
                    x++;
                else if(current=='W')
                    x--;
                }
        }
        return current!='N' || (x==0 && y==0);
    }
};
