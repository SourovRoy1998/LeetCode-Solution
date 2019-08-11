//https://leetcode.com/problems/ordinal-number-of-date/

class Solution {
public:
    bool checkYear(int year){  
        if (year % 400 == 0)  
            return true;  
        if (year % 100 == 0)  
            return false;  
        if (year % 4 == 0)  
            return true;  
        return false;  
    }  
    
    
    
    int dayOfYear(string date) {
        int year,day,month,ans=0;
        year=stoi(date.substr(0,4));
        month=stoi(date.substr(5,2));
        day=stoi(date.substr(8,2));
        int arr1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        int arr2[12]={31,29,31,30,31,30,31,31,30,31,30,31};
        
        if(checkYear(year))
            for(int i=0;i<month-1;i++)
                ans+=arr2[i];
        else
            for(int i=0;i<month-1;i++)
                ans+=arr1[i];
        return ans+day;
        
    }
};
