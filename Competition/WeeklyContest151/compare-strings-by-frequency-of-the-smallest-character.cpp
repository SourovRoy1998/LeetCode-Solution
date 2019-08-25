//https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/

class Solution {
public:
    int f(string s){
        vector<int> arr(26,0);
        for(auto ch : s)
            arr[ch-'a']++;
        for(int i=0;i<26;i++)
            if(arr[i]) return arr[i];
        return 0;
            
    }
    
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n=queries.size(), m=words.size();
        vector<int> result(n,0);
        vector<int> help1(m,0);
        for(int i=0;i<m;i++)
            help1[i]=f(words[i]);
        
        vector<int> help2(n,0);
        for(int i=0;i<n;i++)
            help2[i]=f(queries[i]);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                if(help2[i]<help1[j])
                    result[i]++;
        }
        return result;
            
    }
};
