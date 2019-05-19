//https://leetcode.com/problems/longest-string-chain/

class Solution {
public:
    struct compare
    {
 	   bool operator()(const string& s1,const string& s2)
 	   {
       		return s1.length()<s2.length();
	   }
    };

    int find_length(string arr[], int n)
    {
 	    int* temp = new int[n+1];
 	    for(int i=0; i<n+1; i++)
 	        temp[i] = 1;
 	    sort(arr, arr+n, compare());
 	    map<string, int> m;
 	    for(int i=0; i<n; i++)
 	    {
	 	    int p = arr[i].length();
	 	    string q = arr[i];
	 	    m[q]=i+1;
	 	    for(int j=0; j<p; j++)
	 	    {
 		        char c= q[j];
 		        q.erase(q.begin()+j);
 		        if(m[q]!=0 && temp[m[q]]+1>temp[i+1])
 		        temp[i+1] = temp[m[q]]+1;
 		        q.insert(j,1,c);
	 	    }
	    }
	    int max = 0;
 	    for(int i=1; i<n+1; i++)
 	    {
	         if(temp[i]>max)
		     max = temp[i];	
	    }
 	    return max;
    }
    
    
    int longestStrChain(vector<string>& words) {
        string arr[words.size()];
        for(int i=0;i<words.size();i++)
            arr[i]=words[i];
        return find_length(arr,words.size());
    }
};
