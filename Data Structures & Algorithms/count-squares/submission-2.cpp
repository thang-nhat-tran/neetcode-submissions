class CountSquares {
private:
    unordered_map<int, unordered_map<int, int>> ptsFreq;
public:
    CountSquares() {
    }
    
    void add(vector<int> point) {
        ptsFreq[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int x = point[0], y = point[1];
        // cout << x << " " << y << "\n";
        for (auto& [v, cnt] : ptsFreq[x]) {
            int side = abs(v - y);
            if (side == 0) continue;
            // (x, y)
            // (x, u)
            // (v, x)
            // (u, v)
            res += cnt * ptsFreq[x + side][y] * ptsFreq[x + side][v];
            res += cnt * ptsFreq[x - side][y] * ptsFreq[x - side][v];
        }     
        return res;   
    }
};
