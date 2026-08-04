class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        vector<string> pads = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> results;
        combine(pads, results, digits, "", 0);
        return results;
    }
    void combine(vector<string> &pads, vector<string>& results, string& digits, string curStr, int curIdx) {
        if (curStr != "" && curStr.size() == digits.size()) {
            results.push_back(curStr);
            return;
        }
        for (char c : pads[digits[curIdx] - '0' - 2])
            combine(pads, results, digits, curStr + c, curIdx + 1);
    }
};
