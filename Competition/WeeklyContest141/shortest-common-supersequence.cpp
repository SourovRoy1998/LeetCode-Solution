//https://leetcode.com/problems/shortest-common-supersequence/submissions/


class Solution {
public:
    string lcs(string str1, string str2){
        vector<vector<string>> memoize(str1.length()+1,vector<string> (str2.length()+1,""));
        for(int i=1;i<=str1.length();i++){
            for(int j=1;j<=str2.length();j++){
                if(str1[i-1]==str2[j-1])
                    memoize[i][j]=memoize[i-1][j-1]+str1[i-1];
                else{
                    if(memoize[i-1][j].length()>memoize[i][j-1].length())
                        memoize[i][j]=memoize[i-1][j];
                    else
                        memoize[i][j]=memoize[i][j-1];
                }
            }
        }
        
        /*
        for(int i=0;i<=str1.length();i++){
            for(int j=0;j<=str2.length();j++){
                cout<<memoize[i][j]<<" ";      
            }
            cout<<endl;
        }
        */
        
        return memoize[str1.length()][str2.length()];
    }
    
    
    string shortestCommonSupersequence(string str1, string str2) {
        int i=0,j=0;
        string result="";
        for(auto x: lcs(str1,str2)){
            while(str1[i]!=x)
                result+=str1[i++];
            while(str2[j]!=x)
                result+=str2[j++];
            result+=x;
            i++;j++;
        }
        while(i<str1.length())
            result+=str1[i++];
        while(j<str2.length())
            result+=str2[j++];
        
        return result;
    }
};
