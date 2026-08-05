class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        const auto& values = store[key];
        if (values.empty()) return "";
        int l = 0, r = values.size() - 1;
        int idx = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            auto& [value, time] = values[mid];
            if (time <= timestamp) {
                idx = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (idx == -1) return "";
        return values[idx].first;
    }
};
