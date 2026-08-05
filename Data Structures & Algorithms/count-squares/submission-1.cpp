struct PairHash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        
        // Combine the two hash values (similar to Boost's hash_combine)
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};
class CountSquares {
private:
    unordered_map<int, unordered_set<int>> hor, ver;
    unordered_map<pair<int, int>, int, PairHash> freq;
public:
    CountSquares() {
    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        hor[x].insert(y);
        ver[y].insert(x);
        freq[{x, y}]++;
    }
    
    int count(vector<int> point) {
        int cnt = 0;
        int x = point[0], y = point[1];
        // cout << x << " " << y << "\n";
        for (int v : hor[x]) {
            int edge = abs(v - y);
            if (edge == 0) continue;
            // (x, y)
            // (x, u)
            // (v, x)
            // (u, v)
            if (ver[y].count(x + edge)) {
                int u = x + edge; 
                if (ver[y].count(u)) {
                    cnt += freq[{x, v}] * freq[{u, y}] * freq[{u, v}];
                }
            } else if (ver[y].count(x - edge)) {
                int u = x - edge;
                // cout << " " << u << " " << v << "\n";
                if (ver[y].count(u))
                    cnt += freq[{x, v}] * freq[{u, y}] * freq[{u, v}];
            }
            // cout << '\n';
        }     
        return cnt;   
    }
};
