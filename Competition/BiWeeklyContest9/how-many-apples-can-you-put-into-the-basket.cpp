//https://leetcode.com/problems/how-many-apples-can-you-put-into-the-basket/

class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int count=0,sum=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]+sum<=5000){
                sum+=arr[i];
                count++;
            }
        }
        return count;
    }
};
