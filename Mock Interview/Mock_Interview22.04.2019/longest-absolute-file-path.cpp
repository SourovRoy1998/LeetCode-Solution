//https://leetcode.com/problems/longest-absolute-file-path/
//https://leetcode.com/problems/longest-absolute-file-path/discuss/274718/c%2B%2B-4ms-Solution

class Solution {
public:
    int lengthLongestPath(string input) {
        int answer=0;
        stack<int> stk;
        istringstream iss(input);
        string dir_name;
        
        while(getline(iss,dir_name,'\n')){
            int total_tab=dir_name.find_last_of('\t')+1;
            
            while(!stk.empty() && stk.size()>total_tab)
                stk.pop();
            
            int size_upto=dir_name.substr(total_tab).size()+1+(stk.empty()?0:stk.top());
            stk.push(size_upto);
            if(dir_name.find('.')!=-1)
                answer=max(answer,size_upto-1); //No '/' included in last position
        }
        
        return answer;
    }
};
