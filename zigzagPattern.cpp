class Solution {
public:
    string convert(string s, int numRows) {
if (numRows <= 1 || numRows >= s.length()) {
            return s;
        }

        std::vector<std::string> ans(numRows);
        int i = 0;

        while (i < s.length()) {
            for (int index = 0; index < numRows && i < s.length(); index++) {
                ans[index] += s[i++];
            }
            for (int index = numRows - 2; index > 0 && i < s.length(); index--) {
                ans[index] += s[i++];
            }
        }

        std::string res = "";
        for (const std::string& str : ans) {
            res += str;
        }
        return res;
    }
};