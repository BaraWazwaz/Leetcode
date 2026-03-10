class Solution {
    void sortbit(vector<int>& nums, int l, int r, int k) {
        if (l >= r)
            return;
        int m;
        {
            vector<int> v[2];
            for (int i = l; i <= r; ++i)
                v[(nums[i] >> k) & 1].push_back(nums[i]);
            m = l + v[0].size() - 1;
            for (int i = l; i <= m; ++i)
                nums[i] = v[0][i - l];
            for (int i = m + 1; i <= r; ++i)
                nums[i] = v[1][i - m - 1];
        }
        if (k) {
            sortbit(nums, l, m, k - 1);
            sortbit(nums, m + 1, r, k - 1);
        }
    }
public:
    int maximumGap(vector<int>& nums) {
        int ans = 0;
        sortbit(nums, 0, nums.size() - 1, 29);
        for (int i = 1; i < nums.size(); ++i)
            ans = max(ans, nums[i] - nums[i - 1]);
        return ans;
    }
};