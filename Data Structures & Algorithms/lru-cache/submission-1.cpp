class LRUCache {
public:
    int time;
    unordered_map<int, pair<int, int>> cache;
    set<pair<int, int>> s;
    int cap;
    LRUCache(int capacity) {
        time = 0;
        cap = capacity;
    }
    
    int get(int key) {
        // cout << "GET: " << key << "\n";
        // if (cache.count(key))
        if (!cache.count(key)) return -1;
        auto& [val, t] = cache[key];
        increaseKeyTime(key, val);
        if (cache.size() > cap) evict(); 
        return val;
    }
    
    void put(int key, int value) {
        increaseKeyTime(key, value);
        if (cache.size() > cap) evict(); 
        // cout << "PUT: " << key << " " << value << "\n";
        // cout << cache[key].first << " " << cache[key].second << "\n\n";
    }
    void increaseKeyTime(int key, int val) {
        ++time;
        if (!cache.count(key)) cache[key] = {val, time};
        else {
            auto& [v, t] = cache[key];
            s.erase({t, key});
            t = time;
            v = val;
        }
        s.insert({time, key});
    } 
    void evict() {
        auto [t, key] = *s.begin();
        cache.erase(key);
        s.erase({t, key});
    }
};
