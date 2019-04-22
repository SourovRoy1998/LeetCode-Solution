//https://leetcode.com/problems/longest-absolute-file-path/

class Solution {
public:
    int lengthLongestPath(std::string input) {
        std::stack<int> stk;
        std::istringstream iss(input);
        std::string dir;
        int ans=0;
        while(getline(iss, dir, '\n'))
        {
            int level = dir.find_last_of('\t')+1;
            while(!stk.empty() && stk.size() > level)
                stk.pop();
            int size = dir.substr(level).size()+1+ (stk.empty()?0:stk.top());
            stk.push(size);
            if(dir.find('.') !=-1)
                ans=std::max(ans, size-1);
        }
        return ans;
    }
};
