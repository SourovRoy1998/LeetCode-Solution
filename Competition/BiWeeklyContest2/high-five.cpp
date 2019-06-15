//https://leetcode.com/contest/biweekly-contest-2/problems/high-five/

class Solution {
public:
    static bool comp(vector<int> v1, vector<int> v2){
        //first GROUP BY student_id wise then SORT marks wise in descending order
        if(v1[0]==v2[0])
            return v1[1]>v2[1];
        return v1[0]<v2[0];
    }
    
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        sort(items.begin(),items.end(),comp);
        vector<vector<int>> result;
        
        //After sorting, pick first five elements for each group and
        //calculate the average and then store {id,average} in result vector.  
        int count=0;
        int sum=0;
        int id=items[0][0];
        for(int i=0;i<items.size();i++){
            if(id!=items[i][0]){
                result.push_back({id,sum/count});
                count=0;
                sum=0;
                id=items[i][0];
                
            }
            if(count>=5)
                continue;
            sum+=items[i][1];
            count++;
        }
        result.push_back({id,sum/count});    
        return result;    
    }
};
