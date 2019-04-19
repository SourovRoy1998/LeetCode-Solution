//A string S of lowercase letters is given. We want to partition this string into as many parts aspossible so that
//each letter appears in at most one part, and return a list of integers representing the size of these parts.

//https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char,priority_queue<int>> hmap;
        for(int i=0;i<S.length();i++)
            hmap[S[i]].push(i);
        vector<int> result;
        int temp_length=0;
        int go_upto=hmap[S[0]].top();
        for(int i=0;i<S.length();i++){
            temp_length++;
            go_upto=max(go_upto,hmap[S[i]].top());
            if(i==go_upto){
                result.push_back(temp_length);
                temp_length=0;
            }    
        }
        
        if(temp_length)
            result.push_back(temp_length);
        return result;
    }
};
