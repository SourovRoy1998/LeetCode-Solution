//https://leetcode.com/problems/insert-delete-getrandom-o1/


class RandomizedSet {
public:
    vector<int> data;
    unordered_map<int,int> hmap;
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hmap.find(val)!=hmap.end()) return false;
        data.push_back(val);
        hmap[val]=data.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hmap.find(val)==hmap.end()) return false;
        int index=hmap[val];
        data[index]=data[data.size()-1];
        hmap[data[index]]=index;
        data.pop_back();
        hmap.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(data.size()==0) return -1;
        if(data.size()==1) return data[0];
        int num=rand()%data.size();
        return data[num];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
