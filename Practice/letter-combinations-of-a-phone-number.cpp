//https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> vec={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result={""},temp;
        for(int i=0;i<digits.size();i++){
            string str=vec[digits[i]-'0'];
            temp={};
            for(int j=0;j<str.size();j++)
                for(int k=0;k<result.size();k++)
                    temp.push_back(result[k]+str[j]);
            result=temp;
        }
        return result;
    }
};
