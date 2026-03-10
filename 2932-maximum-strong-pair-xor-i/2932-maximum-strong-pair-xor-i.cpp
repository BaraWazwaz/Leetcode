class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int ans = 0;
        auto& v = nums;
        int n = v.size();
        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i) {
            auto l = lower_bound(v.begin(), v.end(), v[i] * 1) - v.begin();
            auto r = upper_bound(v.begin(), v.end(), v[i] * 2) - v.begin() - 1;
            for (int j = l; j <= r; ++j)
                ans = max(ans, v[i] ^ v[j]);
        }
        return ans;
    }
};