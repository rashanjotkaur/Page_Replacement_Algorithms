class LRUCache{
private:

public:
    list<pair<int, int>> lst;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    int size;
    LRUCache(int cap){
        size = cap;
        lst.clear();
        mp.clear();
    }
    
    int get(int key){
        if(mp.find(key) == mp.end())
            return -1;
            
        auto it = mp[key];
        int val = it->second;
        lst.erase(it);
        lst.push_front({key, val});
        mp[key] = lst.begin();
        
        return val;
    }
    
     void set(int key, int value){
        // Case 1: there is no space and key is not present
        if(mp.find(key) == mp.end()){
            if(lst.size() == size){
                auto last = lst.back();
                mp.erase(last.first);
                lst.pop_back();
            }
        }
        // Case 2: there is space and key is not present
        else{
            auto it = mp[key];
            lst.erase(it);
        }
            
        lst.push_front({key, value});
        mp[key] = lst.begin();
    }
};
