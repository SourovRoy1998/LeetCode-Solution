//https://leetcode.com/contest/biweekly-contest-4/problems/number-of-days-in-a-month/


class Solution {
public:
    bool checkYear(int year)  
{  
    // If a year is multiple of 400,  
    // then it is a leap year  
    if (year % 400 == 0)  
        return true;  
  
    // Else If a year is muliplt of 100,  
    // then it is not a leap year  
    if (year % 100 == 0)  
        return false;  
  
    // Else If a year is muliplt of 4,  
    // then it is a leap year  
    if (year % 4 == 0)  
        return true;  
    return false;  
}  
    
    int numberOfDays(int Y, int M) {
        if(M==1) return 31;
        else if(M==1) return 31;
        else if(M==2 && checkYear(Y)) return 29;
        else if(M==2) return 28; 
        else if(M==3) return 31;
        else if(M==4) return 30;
        else if(M==5) return 31;
        else if(M==6) return 30;
        else if(M==7) return 31;
        else if(M==8) return 31;
        else if(M==9) return 30;
        else if(M==10) return 31;
        else if(M==11) return 30;
        else if(M==12) return 31;
        return -1;
    }
};
