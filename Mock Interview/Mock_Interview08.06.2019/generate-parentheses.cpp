//https://leetcode.com/problems/generate-parentheses/


class Solution {

private:
    void generateCombinations(set<string>& s, string pattern, int n, int open, int match) {
        if (pattern.size() == 2*n) {
            s.insert(pattern);
        }
        else {
            if (open + match < n )
                generateCombinations(s, pattern+"(", n, open+1, match);
            
            if (open > 0)
                generateCombinations(s, pattern+")", n, open-1, match+1);                
        }            
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        set<string> s;

        generateCombinations(s, "(", n, 1, 0);
       
        for (auto& word : s)
            sol.push_back(word);

        return sol;
    }
};
