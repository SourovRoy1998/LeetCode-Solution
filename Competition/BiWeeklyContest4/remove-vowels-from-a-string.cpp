//https://leetcode.com/contest/biweekly-contest-4/problems/remove-vowels-from-a-string/

class Solution {
public:
    bool isVowel(char x){
        if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='A' || x=='E' || x=='I' || x=='O' || x=='U') return true;
        return false;
    }
    
    string removeVowels(string S) {
        string result="";
        for(auto x : S)
            if(!isVowel(x)) result+=x;
        return result;
    }
};
