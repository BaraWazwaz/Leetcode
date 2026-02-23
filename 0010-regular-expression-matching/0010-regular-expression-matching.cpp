class Solution {
private:
    bool match(char s, char p) {
        return p == '.' || s == p;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s.insert(s.begin(), '*');
        p.insert(p.begin(), '*');
        auto dp = vector(n + 1, vector(m + 1, false));
        for (int j = 0; j <= m; j += 2)
            if (p[j] == '*')
                dp[0][j] = true;
            else
                break;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (p[j] == '*')
                    dp[i][j] = dp[i][j - 2] ||
                               dp[i - 1][j] && match(s[i], p[j - 1]);
                else
                    dp[i][j] = dp[i - 1][j - 1] && match(s[i], p[j]);
        return dp[n][m];
    }
};