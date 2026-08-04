class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //1. build adj 
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //2. dfs and make color on the way -> check containing circle
        int cnt = 0;
        vector<bool> vst(n, false);
        if (!findCycle(-1, 0, adj, vst, cnt)) return false;
        if (cnt != n) return false;
        return true;

    }
    bool findCycle(int par, int u, vector<vector<int>>& adj, vector<bool>& vst, int& cnt) {
        ++cnt;
        vst[u] = true;
        for (int& v : adj[u]) {
            if (v == par) continue;
            if (vst[v]) return false;
            if (!findCycle(u, v, adj, vst, cnt)) return false;
        }
        return true;
    }


};
