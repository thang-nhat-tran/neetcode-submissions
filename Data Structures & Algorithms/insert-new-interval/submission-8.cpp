class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {newInterval};
        vector<vector<int>> res;
        bool added = false;

        int start = intervals[0][0];
        int end = intervals[0][1];
        for (auto& itv  : intervals) {
            int l = itv[0], r = itv[1];
                    // cout << l << "  " << r << "\n";
                    // cout << start << " " << end << "\n\n";

            if (l <= end) {
                end = max(end, r);
            } else {
                res.push_back({start, end});
                start = l;
                end = r;
            }
            if (!added && newInterval[0] <= end) {
                if (newInterval[1] >= start) {
                    start = min(start, newInterval[0]);
                    end = max(end, newInterval[1]);
                } else {
                    res.push_back(newInterval);
                }
                added = true;
            }
        }
        res.push_back({start, end});
        if (!added) res.push_back(newInterval);
        return res;
    }
};
