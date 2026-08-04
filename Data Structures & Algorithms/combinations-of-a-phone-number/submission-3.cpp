class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        vector<string> pads = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> results;
        string curStr = "";
        combine(pads, results, digits, curStr, 0);
        return results;
    }
    void combine(vector<string> &pads, vector<string>& results, string& digits, string& curStr, int curIdx) {
        if (curStr != "" && curStr.size() == digits.size()) {
            results.push_back(curStr);
            return;
        }
        for (char c : pads[digits[curIdx] - '0' - 2])
         {  
            curStr += c;
             combine(pads, results, digits, curStr, curIdx + 1);
            curStr.pop_back();
        }
    }
};
