class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<int> dp(len, false);
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        // dp[i] means:
        // Whether we can constructure the string [0...i] of s from the words in wordDicts;
        for (int i = 0; i < len; i++) {
            string curS = "";
            for (int j = i; j >= 0; j--) {
                curS = s[j] + curS;
                if (wordSet.count(curS)) {
                    dp[i] |= (j == 0 || dp[j - 1]);
                }
                if (dp[i]) break;
            }
            // cout << curS << " " << dp[i] << "\n";
        }
        return dp[len - 1];
    }
};
