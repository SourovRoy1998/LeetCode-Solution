//https://leetcode.com/problems/prison-cells-after-n-days/

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> daytwo(cells.size());
        vector<int> temp(cells.size());
        
        for(int j=1;j<cells.size()-1;j++){
                if((cells[j+1]==0 && cells[j-1]==0) || (cells[j-1]==1 && cells[j+1]==1))
                   daytwo[j]=1;
                else
                   daytwo[j]=0;
            }
            cells=daytwo;
        
        for(int i=1;i<N;i++){
            for(int j=1;j<cells.size()-1;j++){
                if((cells[j+1]==0 && cells[j-1]==0) || (cells[j-1]==1 && cells[j+1]==1))
                   temp[j]=1;
                else
                   temp[j]=0;
            }
            cells=temp;
            if(daytwo==cells){
                N=(N-1)%i+1;
                i=0;
            }
        }
        return cells;
    }
};
