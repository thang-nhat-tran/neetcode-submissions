class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int numRow = grid.size();
        int numCol = grid[0].size();
        vector<vector<int>> time(numRow, vector<int>(numCol, INT_MAX));
        queue<tuple<int, int, int>> q;
        for (int x = 0; x < numRow; x++) {
            for (int y = 0; y < numCol; y++) {
                if (grid[x][y] == 2)
                    {q.push({x, y, 0}); time[x][y] = 0; }
            }
        }

        while(!q.empty()) {
            auto [x, y, t] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int u = x + dx[i];
                int v = y + dy[i];
                if (u < 0 || u >= numRow || v < 0 || v >= numCol || grid[u][v] != 1) {
                    continue;
                }
                if (time[u][v] > time[x][y] + 1) {
                    time[u][v] = time[x][y] + 1;
                    q.push({u, v, time[u][v]});
                }
            }
        }
        int res = 0;
        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numCol; j++) {
                if (grid[i][j] == 1) {
                    if (time[i][j] == INT_MAX) return -1;
                    res = max(res, time[i][j]);
                }
            }
        }
        return res;
    }
};
