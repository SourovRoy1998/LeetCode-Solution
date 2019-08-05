//https://leetcode.com/problems/lru-cache/

class LRUCache {
public:
    int size;
    list<vector<int>> cache;
    unordered_map<int,list<vector<int>>::iterator> hmap;
    
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        if(hmap.find(key)==hmap.end()) return -1;
        vector<int> vec=*hmap[key];
        cache.erase(hmap[key]);
        cache.push_front(vec);
        hmap[key]=cache.begin();
        return vec[1];
    }
    
    void put(int key, int value) {
        if(hmap.find(key)==hmap.end()){ 
            if(cache.size()==size){
                hmap.erase(cache.back()[0]);
                cache.pop_back();
            }
            cache.push_front({key,value});
            hmap[key]=cache.begin();            
        }
        else{
            cache.erase(hmap[key]);
            cache.push_front({key,value});
            hmap[key]=cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
