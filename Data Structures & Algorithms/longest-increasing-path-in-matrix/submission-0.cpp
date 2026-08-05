class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        unordered_map<int, unordered_map<int, int>> path;
        priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> pq;
        vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        int n = matrix.size(), m = matrix[0].size();
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                pq.push({matrix[x][y], 0, x, y});
            }
        }
        int res = 0;
        // int turn = 0;
        
        while(!pq.empty()) {
            // ++turn;
            // if (turn == 20) break;
        
            auto [val, p, x, y] = pq.top();
            // cout << val << " " << p << " " << x << " " << y << "\n";
            pq.pop();
            res = max(res, p);
            if (p < path[x][y]) continue;
            for (int i = 0; i < dir.size(); i++) {
                int u = x + dir[i].first;
                int v = y + dir[i].second;
                if (u < 0 || u >= n || v < 0 || v >= m || matrix[u][v] <= matrix[x][y] || path[x][y] + 1 <= path[u][v]) continue;
                path[u][v] = path[x][y] + 1;
                pq.push({matrix[x][y], path[u][v], u, v});
            }
        }
        return res + 1;
    }
};
