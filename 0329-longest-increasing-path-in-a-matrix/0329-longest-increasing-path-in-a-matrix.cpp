class Solution {
private:
    int dx[4] = { +1, +0, -1, -0 };
    int dy[4] = { +0, +1, +0, -1 };
    bool bound(int x, int y, int n, int m) {
        return 0 <= x and x < n and 0 <= y and y < m;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        map<int,vector<pair<int,int>>, greater<int>> org;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                org[matrix[i][j]].push_back({ i, j });
        vector dp (n, vector (m, make_pair(1,0)));
        // dp[x][y] = { maxLen, dir }
        for (auto& [val, v] : org)
            for (auto& [x, y] : v)
                for (int i = 0; i < 4; ++i) {
                    int xi = x + dx[i];
                    int yi = y + dy[i];
                    if (bound(xi, yi, n, m) and matrix[x][y] < matrix[xi][yi])
                        dp[x][y] = max(dp[x][y], { dp[xi][yi].first + 1, i });
                }
        int ans = 0;
        for (auto& r : dp)
            for (auto& [l, p] : r)
                ans = max(ans, l);
        return ans;
    }
};