class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        stack<int> st;
        int n = a.size();
        vector<int> res(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while(!st.empty()) {
                if (a[st.top()] <= a[i]) st.pop();
                else break;
            }
            if (!st.empty()) {
                res[i] = st.top() - i;
            }
            st.push(i);
        }
        return res;
    }
};
