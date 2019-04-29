//https://leetcode.com/problems/most-common-word/


class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for (int i=0; i< paragraph.length(); i++) {
            if(ispunct(paragraph[i]))
                paragraph[i]=' ';
            
        }
        
        map<string,int> hmap;
        istringstream iss(paragraph);
        string temp;
        while(getline(iss, temp, ' ')){
            if(temp=="")
                continue;
            string temp2="";
            for(auto x:temp)
                if(isalpha(x))
                    temp2+=tolower(x);
            hmap[temp2]+=1;
            //cout<<temp2<<endl;;
        }
        
        for(auto x: banned){
            if(hmap.find(x)!=hmap.end())
                hmap.erase(x);
        }
        int maxi=-1;
        for(auto x:hmap)
            if(x.second>maxi){
                cout<<x.first<<endl;
                temp=x.first;
                maxi=x.second;
            }
        
        return temp;
    }
};
