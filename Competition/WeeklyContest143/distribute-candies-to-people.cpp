//https://leetcode.com/problems/distribute-candies-to-people/


class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people);
        int i=1,j=0;
        while(candies){
            if(candies<=i){
                result[j%num_people]+=candies;
                candies=0;
                break;
            }
            
            candies-=i;
            result[j%num_people]+=i;
            i++;j++;
        }
            return result;
        }
        
        /*
        int n=candies/num_people;
        for(int i=0;i<num_people;i++){
            result[i]=n*(n-1)*num_people/2+n*(i+1);
        }
        
        return result;
        */
};
