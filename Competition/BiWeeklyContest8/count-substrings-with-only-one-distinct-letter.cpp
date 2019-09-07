//https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter/

class Solution {
public:
    int countLetters(string S) {
        vector<int> vec(S.length(),1);
        int answer=0;
        for(int i=1;i<S.length();i++){
            if(S[i-1]==S[i]) vec[i]=vec[i-1]+1;
            answer+=vec[i];
        }
        return answer+1;
    }
};
