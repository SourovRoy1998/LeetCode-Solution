//https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    bool row[9][9]={};
    bool col[9][9]={};
    bool grid[9][9]={};
    bool found=false;

    void place(int n,vector<vector<char>>& matrix){
        if(n==81){
            found=true;
            return;
        }
    
        int i=n/9,j=n%9;
        int index=(i/3)*3+(j/3)%3;
        if(matrix[i][j]=='.'){
            for(int c=0;c<9;c++){
                if(!row[i][c] && !col[j][c] && !grid[index][c]){
                    matrix[i][j]=c+'1';
                    row[i][c]=true;
                    col[j][c]=true;
                    grid[index][c]=true;
        
                    place(n+1,matrix);
                    if(found==true)
                        return;
                    matrix[i][j]='.';
                    row[i][c]=false;
                col[j][c]=false;
                grid[index][c]=false;
                }    
            }
        }
        else
            place(n+1,matrix);
        return;
    }
    
    void solveSudoku(vector<vector<char>>& matrix) {
        for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if(matrix[i][j]!='.'){
                row[i][matrix[i][j]-'1']=true;
                col[j][matrix[i][j]-'1']=true;
                grid[(i/3)*3+(j/3)%3][matrix[i][j]-'1']=true;
            }
    place(0,matrix);
    return;
    }
};
