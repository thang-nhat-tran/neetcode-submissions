class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // 4 1 0 7
        // 2 2 1 1

        // 0 1 4 7
        // 1 2 2 1

        // t1: 1 3 6 8
        // t2: 2 5 8 9
        // t3: 3 7 9 10
        int n = position.size();
        vector<array<int, 2>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {position[i], speed[i]};
        }
        sort(a.begin(), a.end());
        double last = 0;
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            auto& [p, s] = a[i];
            double time = 1.0 * (target - p) / s;
            if (time > last) {
                res++;
                last = time;
            }
        }
        return res;
    }
};
