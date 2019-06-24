//https://leetcode.com/problems/statistics-from-a-large-sample/



class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double mini=INT_MAX;
        double maxi=INT_MIN;
        double mode=0;
        int total_num=0;
        int max_freq=0;
        double total_sum=0;
        for(int i=0;i<count.size();i++){
            if(count[i]){
                mini=min(mini,(double)i);
                maxi=max(maxi,(double)i);
                total_num+=count[i];
                total_sum+=count[i]*i;
                if(count[i]>max_freq){
                    max_freq=count[i];
                    mode=(double)i;
                }
            }
        }
        double mean=total_sum/total_num;
        double median;
        
        if(total_num%2==0){
            int index1=total_num/2;
            int index2=index1+1;
            bool flag1=false,flag2=false;
            
            int upto=0;
            double median_sum=0;
            for(int i=0;i<count.size();i++){
                upto+=count[i];
                if(upto>=index1 && flag1==false){
                    median_sum+=i;flag1=true;
                }
                if(upto>=index2 && flag2==false){
                    median_sum+=i;flag2=true;
                    break;
                }       
            }
            
            median=median_sum/2;
        }
        else{
            int index=total_num/2;
            int upto=0;
            for(int i=0;i<count.size();i++){
                upto+=count[i];
                if(upto>=index){
                    median=(double)i;
                    break;
                }
            }
        }
        
        return {mini,maxi,mean,median,mode};
        
    }
};
