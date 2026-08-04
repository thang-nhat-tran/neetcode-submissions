class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> pads = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> results;
        combine(pads, results, digits, "", 0);
        return results;
    }
    void combine(vector<string> &pads, vector<string>& results, string& digits, string curStr, int curIdx) {
        if (curStr.size() == digits.size() && curStr != "") results.push_back(curStr);
        if (curIdx >= digits.size()) return;
        for (int i = curIdx; i < digits.size(); i++) {
            for (char c : pads[digits[i] - '0' - 2])
            combine(pads, results, digits, curStr + c, i + 1);
        }
    }
};
