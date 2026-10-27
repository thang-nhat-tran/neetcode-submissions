class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> pattern = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        for (char c : s) {
            if (pattern.count(c)) {
                st.push(c);
            } else {
                if (st.empty() || pattern[st.top()] != c) return false;
                st.pop();
            }
        }
        return (st.empty());
    }
};
