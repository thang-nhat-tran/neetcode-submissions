class Solution {
    vector<vector<int>> dp;

public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if (m + n != s3.length()) return false;
        auto dp = vector<vector<bool>>(m + 1, vector<bool>(n + 1, false));
        // cout << ("" == "");
        dp[m][n] = true;
        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                if (i < m && s1[i] == s3[i + j]) {
                    if (j == n || dp[i + 1][j]) {
                        dp[i][j] = true;
                    }
                }
                if (j < n && s2[j] == s3[i + j]) {
                    if (i == m || dp[i][j + 1]) {
                        dp[i][j] = true;
                    }
                }
            }
        }
        return dp[0][0];
    }
};