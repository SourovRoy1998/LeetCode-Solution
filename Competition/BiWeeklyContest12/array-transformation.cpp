//https://leetcode.com/problems/array-transformation/

class Solution {
public:
    vector<int> change(vector<int> arr){
        int count=0;
        vector<int> temp(arr.size(),0);
        temp[0]=arr[0];
        temp[arr.size()-1]=arr[arr.size()-1];
        
        for(int i=1;i<arr.size()-1;i++){
            if(arr[i]<arr[i-1] && arr[i]<arr[i+1]){ temp[i]=arr[i]+1; count++;}
            else if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){ temp[i]=arr[i]-1; count++;}
            else temp[i]=arr[i];
        }
        
        if(count) return change(temp);
        return temp;
    }
    
    vector<int> transformArray(vector<int>& arr) {
        return change(arr);
    }
};
