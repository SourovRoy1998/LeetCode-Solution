//https://leetcode.com/contest/biweekly-contest-7/problems/design-file-system/

class FileSystem {
public:
    map<string,int> hmap;
    FileSystem() {
        
    }
    
    bool create(string path, int value) {
        cout<<path<<endl;
        if(hmap.find(path)!=hmap.end()) return false;
        int i=-1;
        for(int j=0;j<path.length();j++) 
            if(path[j]=='/') i=j;
        if(i>=1 && hmap.find(path.substr(0,i))==hmap.end()) return false;
                                            
        hmap[path]=value;
        return true;
    }
    
    int get(string path) {
        if(hmap.find(path)==hmap.end()) return -1;
        return hmap[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->create(path,value);
 * int param_2 = obj->get(path);
 */
