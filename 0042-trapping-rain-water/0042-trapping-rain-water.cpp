class Solution {
public:
    int trap(vector<int>& height) {
        auto l = height;
        auto r = height;
        int n = height.size();
        for (int i = 1; i < n; ++i)
            l[i] = max(l[i], l[i - 1]);
        for (int i = n - 2; i >= 0; --i)
            r[i] = max(r[i], r[i + 1]);
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans += min(l[i], r[i]) - height[i];
        return ans;
    }
};