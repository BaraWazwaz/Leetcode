class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        auto dp = vector(n, vector(n + 1, false));
        // dp[start][end] = is s[start:len] a palindrom ?
        for (int i = 0; i < n; ++i)
            dp[i][1] = true;
        for (int i = 0; i < n - 1; ++i)
            dp[i][2] = s[i] == s[i + 1];
        for (int len = 3; len <= n; ++len)
            for (int i = 0; i + len <= n; ++i)
                dp[i][len] = dp[i + 1][len - 2] && s[i] == s[i + len - 1];
        for (int len = n; len >= 1; --len)
            for (int i = 0; i < n; ++i)
                if (dp[i][len])
                    return s.substr(i, len);
        return "";
    }
};