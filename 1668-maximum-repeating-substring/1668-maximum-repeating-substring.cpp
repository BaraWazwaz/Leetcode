class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size(), m = word.size();
        auto dp = vector(n, 0);
        for (int i = 0; i + m <= n; ++i)
            dp[i] = sequence.substr(i, m) == word;
        for (int i = m; i < n; ++i)
            if (dp[i])
                dp[i] += dp[i - m];
        return *max_element(dp.begin(), dp.end());
    }
};