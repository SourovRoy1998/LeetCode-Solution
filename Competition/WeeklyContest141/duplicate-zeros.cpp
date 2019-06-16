//https://leetcode.com/problems/duplicate-zeros/

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]==0){
                int temp=arr[i+1];
                arr[i+1]=0;
                int j=i+2;
                while(j<arr.size()){
                    int temp2=arr[j];
                    arr[j]=temp;
                    temp=temp2;
                    j++;
                }
                i++;
            }
        }
    }
};
