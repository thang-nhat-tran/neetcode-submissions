struct PairHash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        // Fetch hashes for individual components
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        
        // Combine the two hashes (Boost-style combination formula)
        // The magic constant helps distribute bits evenly and prevent collisions
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};

class Solution {
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int num_row = heights.size();
        int num_col = heights[0].size();
        unordered_set<pair<int, int>, PairHash> pacific, atlantic;
        vector<vector<bool>> vst(num_row, vector<bool>(num_col, false));
        //pacific
        for (int x = 0; x < num_row; x++) {
            if (!vst[x][0]) dfs(x, 0, num_row, num_col, vst, pacific, heights);
        }
        for (int y = 0; y < num_col; y++) {
            if (!vst[0][y]) dfs(0, y, num_row, num_col, vst, pacific, heights);
        }
        vst.assign(num_row, vector<bool>(num_col, false));
        //atlantic
        for (int x = 0; x < num_row; x++) {
            if (!vst[x][num_col - 1]) dfs(x, num_col - 1, num_row, num_col, vst, atlantic, heights);
        }
        for (int y = 0; y < num_col; y++) {
            if (!vst[num_row - 1][y]) dfs(num_row - 1, y, num_row, num_col, vst, atlantic, heights);
        }
        vector<vector<int>> res;
        for (auto& cell : pacific) {
            if (atlantic.count(cell)) res.push_back({cell.first, cell.second});
        }
        return res;
    }
    void dfs(int u, int v, int& row, int& col, vector<vector<bool>>& vst, unordered_set<pair<int, int>, PairHash>& cells, vector<vector<int>>& heights) {
        vst[u][v] = true;
        cells.insert({u, v});
        for (auto& [x, y] : dir) {
            int new_u = x + u;
            int new_v = y + v;
            if (new_u < 0 || new_u >= row || new_v < 0 || new_v >= col || vst[new_u][new_v] || heights[new_u][new_v] < heights[u][v]) continue;
            dfs(new_u, new_v, row, col, vst, cells, heights);
        }
    }
};
