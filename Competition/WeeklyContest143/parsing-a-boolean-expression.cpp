//https://leetcode.com/problems/parsing-a-boolean-expression/


class Solution {
public:
    //break down comma separared expressions maintaining valid bracket positions 
    vector<string> tokenize(string s){
        vector<string> result;
        string token="";
        int brace=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==',' && brace==0){
                result.push_back(token);
                token="";
                continue;
            }
            if(s[i]=='(') brace++;
            if(s[i]==')') brace--;
            token+=s[i];
        }
        if(!token.empty()) result.push_back(token);
        
        return result;
    }
    
    
    bool parseBoolExpr(string expression) {
        int n=expression.length();
        if(expression=="t") return true; //Base Cases
        if(expression=="f") return false;
        
        if(expression[0]=='!') return !parseBoolExpr(expression.substr(2,n-3)); //if '!' then recursive evaluate the
                                                                                //expression inside and return the inverted value 
        
        string s=expression.substr(2,n-3);
        vector<string> token=tokenize(s); //tokenize the comma separated expressions
        
        bool result=parseBoolExpr(token[0]); 
        if(expression[0]=='&'){    //for 'AND', find 'AND' of all the expressions recursively
            for(int i=1;i<token.size();i++)
                result=result && parseBoolExpr(token[i]);
        }
        if(expression[0]=='|'){    ////for 'OR', find 'OR' of all the expressions recursively
            for(int i=1;i<token.size();i++)
                result=result || parseBoolExpr(token[i]);
        }
        return  result;
    }
};
