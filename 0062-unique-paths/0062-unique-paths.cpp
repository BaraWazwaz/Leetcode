class Solution {
public:
    int uniquePaths(int m, int n) {
        --n, --m;
        if (n < m)
            swap(n, m);
        n += m;
        long long ans = 1;
        for (int i = 0; i < m; ++i)
            ans = ans * (n - i) / (i + 1);
        return ans;
    }
};