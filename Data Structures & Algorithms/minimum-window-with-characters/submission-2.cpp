class Solution {
public:
    string minWindow(string s, string t) {
        pair<int, int> res = {-1, -1};
        unordered_map<char, int> t_freq;
        unordered_set<char> set_t, correct;
        for (char c : t) t_freq[c]++, set_t.insert(c);

        unordered_map<char, int> cnt;
        for (int l = 0, r = 0; r < s.size(); r++) {
            cnt[s[r]]++;

            // check correct
            // for (int i = 0; i < 26; i++) {
            //     char upper = 'A' + i;
            //     char lower = 'a' + i;
            //     if (t_freq[upper] > 0 && cnt[upper] < t_freq[upper]) {
            //         ok = false;
            //         break;
            //     }
            //     if (t_freq[lower] > 0 && cnt[lower] < t_freq[lower]) {
            //         ok = false;
            //         break;
            //     }
            // }
            if (t_freq.count(s[r]) && cnt[s[r]] >= t_freq[s[r]]) {
                correct.insert(s[r]);
            }

            while(correct.size() == set_t.size() && l <= r) {
                // cout << l << " " << r << "\n";
                if (res.first == -1 || (r - l + 1) < res.second - res.first + 1) {
                    res = {l, r};
                }
                if (t_freq.count(s[l]) && cnt[s[l]] - 1 < t_freq[s[l]]) break;
                cnt[s[l]]--;
                l++;
            }
            
        }
        if (res.first == -1) return "";
        return s.substr(res.first, res.second - res.first + 1);
    }
};
