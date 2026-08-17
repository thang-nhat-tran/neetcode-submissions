class Solution {
public:
    string minWindow(string s, string t) {
        pair<int, int> res = {-1, -1};
        unordered_map<char, int> count_t, window;
        for (char c : t) count_t[c]++;
        int need = count_t.size(), have = 0;

        for (int l = 0, r = 0; r < s.size(); r++) {
            window[s[r]]++;

            if (count_t.count(s[r]) && window[s[r]] == count_t[s[r]]) {
                have++;
            }

            while(need == have) {
                if (res.first == -1 || (r - l + 1) < res.second - res.first + 1) {
                    res = {l, r};
                }
                window[s[l]]--;
                if (count_t.count(s[l]) && window[s[l]] < count_t[s[l]]) {
                    have--;
                }
                l++;
            }
            
        }
        if (res.first == -1) return "";
        return s.substr(res.first, res.second - res.first + 1);
    }
};
