//https://leetcode.com/problems/day-of-the-week/


class Solution {
public:
    int getWeekDay(int yy, int mm, int dd) 
{
	//formula to get weekday number
	int rst =                                                     
		dd                                                      
		+ ((153 * (mm + 12 * ((14 - mm) / 12) - 3) + 2) / 5) 
		+ (365 * (yy + 4800 - ((14 - mm) / 12)))
		+ ((yy + 4800 - ((14 - mm) / 12)) / 4)
		- ((yy + 4800 - ((14 - mm) / 12)) / 100)
		+ ((yy + 4800 - ((14 - mm) / 12)) / 400)
		- 32045;

	return (rst+1)%7 ;
}
    
    
    
    
    string dayOfTheWeek(int day, int month, int year) {
        const char *Names[] = {"Sunday","Monday", "Tuesday","Wednesday", "Thursday", "Friday", "Saturday"};
	    int d = 0;
        d= getWeekDay(year,month,day);
        return Names[d];
        
    }
};
