class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int minLen = INT_MAX;
        for (string& s : strs)
            minLen = min(minLen + 0ull, s.size() + 0ull);
        for (int i = 0; i < minLen; ++i) {
            bool match = true;
            for (int j = 1; j < strs.size(); ++j)
                if (strs[j][i] != strs[j - 1][i]) {
                    match = false;
                    break;
                }
            if (!match)
                return ans;
            ans.push_back(strs[0][i]);
        }
        return ans;
    }
};