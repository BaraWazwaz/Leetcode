class Solution {
private:
    int mul(int a, int b, int m) {
        int ans = (1ll * a * b) % m;
        ans += (ans < 0) * m;
        return ans;
    }
    int power(int a, int p, int m) {
        int ans = 1;
        while (p) {
            if (p & 1)
                ans = mul(ans, a, m);
            a = mul(a, a, m);
            p >>= 1;
        }
        return ans;
    }
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for (int i = 0; i < variables.size(); ++i) {
            int a = variables[i][0];
            int b = variables[i][1];
            int c = variables[i][2];
            int m = variables[i][3];
            if (target == power(power(a, b, 10), c, m))
                ans.emplace_back(i);
        }
        return ans;
    }
};