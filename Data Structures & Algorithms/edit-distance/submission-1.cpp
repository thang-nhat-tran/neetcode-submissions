class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        if (n1 == 0 || n2 == 0) return max(n1, n2);
        vector<vector<int>> dp(n1, vector<int>(n2, INT_MAX));
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (word1[i] == word2[j]) {
                    if (i == 0 || j == 0) dp[i][j] = min(dp[i][j], max(i, j));
                    else {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                    }
                    continue;
                }
                // insert
                if (j == 0) {
                    dp[i][j] = min(dp[i][j], 1 + i + 1);
                } else {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
                }
                // delete
                if (i == 0)
                    dp[i][j] = min(dp[i][j], 1 + j + 1);
                else 
                    dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j]);
                // replace
                   if (i == 0 || j == 0) dp[i][j] = min(dp[i][j], max(i, j) + 1);
                    else {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                    }
            }
        }
        return dp[n1 - 1][n2 - 1];
    }
};
