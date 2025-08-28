class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        vector<int> dp (nums.size(), INT_MIN);
        dp[0] = nums[0], dp[1] = nums[1], dp[2] = max(nums[0] + nums[2], nums[1]);
        for (int i = 3; i < nums.size(); ++i)
            dp[i] = max({dp[i - 1], dp[i - 2] + nums[i], dp[i - 3] + nums[i]});
        return dp.back();
    }
};