class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt_s1(26, 0);
        for (char c : s1) {
            cnt_s1[c - 'a']++;
        }
        vector<int> cur(26, 0);
        for (int l = 0, r = 0; r < s2.size(); r++) {
            int char_r = s2[r] - 'a';
            cur[char_r]++;
            while(cur[char_r] > cnt_s1[char_r]) {
                int char_l = s2[l] - 'a';
                cur[char_l]--;
                l++;
            }
            if (l <= r && r - l + 1 == s1.size()) return true;
        }
        return false;
    }
};
