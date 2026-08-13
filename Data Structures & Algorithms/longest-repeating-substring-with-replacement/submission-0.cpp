class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        for (int c = 0; c < 26; c++) {
            int cnt = 0;
            for (int l = 0, r = 0; r < s.size(); r++) {
                cnt += ((s[r] - 'A') == c);
                int other = (r - l + 1)  - cnt;
                while(other > k) {
                    cnt -= ((s[l] - 'A') == c);
                    l++;
                    other = (r - l + 1) - cnt;
                }
                res = max(res, r - l + 1);
                // if (res == 7) {
                //     cout << c << " " << l << " " << r << "\n";
                // }
            }
        }        
        return res;
    }
};
