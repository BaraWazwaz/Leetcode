class Solution {
    using Row = vector<long long>;
    using Matrix = vector<vector<long long>>;
    Matrix mul(Matrix a, Matrix b) {
        return {
            {
                a[0][0] * b[0][0] + a[0][1] * b[1][0],
                a[0][0] * b[0][1] + a[0][1] * b[1][1]
            }, {
                a[1][0] * b[0][0] + a[1][1] * b[1][0],
                a[1][0] * b[0][1] + a[1][1] * b[1][1]
            }
        };
    }
    Matrix power(Matrix a, int p) {
        Matrix ans = {
            { 1, 0 },
            { 0, 1 }
        };
        while (p) {
            if (p & 1)
                ans = mul(ans, a);
            a = mul(a, a);
            p >>= 1;
        }
        return ans;
    }
public:
    int climbStairs(int n) {
        Matrix a = {
            { 1, 1 },
            { 1, 0 }
        };
        return power(a, n + 1)[1][0];
    }
};