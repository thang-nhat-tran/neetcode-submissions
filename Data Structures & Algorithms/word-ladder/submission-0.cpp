class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int start = n;
        int dest = -1;
        n++;
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < wordList.size(); i++) {
            auto& w1 = wordList[i];
            if (w1 == endWord) dest = i;
            if (canConvert(beginWord, w1)) {
                // cout << beginWord << " -> " << w1 << "\n";
                adj[start].push_back(i);
            } 
            for (int j = i + 1; j < wordList.size(); j++) {
                auto& w2 = wordList[j];
                if (canConvert(w1, w2)) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    // cout << w1 << " -> " << w2 << "\n";
                }
            }
        }
        if (dest == -1) return 0;
        vector<int> d(n, INT_MAX);
        d[start] = 1;
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            auto u = q.front();
            // if (u < wordList.size()) cout << wordList[u] << "\n";
            // else cout << beginWord << '\n';
            q.pop();
            for (int v : adj[u]) {
                if (d[v] > d[u] + 1) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        if (d[dest] == INT_MAX) return 0;
        return d[dest];
    }
    bool canConvert(string& w1, string& w2) {
        bool diff = false;
        for (int i = 0; i < w1.size(); i++) {
            if (w1[i] != w2[i]) {
                if (diff) return false;
                diff = true;
            } 
        }
        return true;
    }
};
