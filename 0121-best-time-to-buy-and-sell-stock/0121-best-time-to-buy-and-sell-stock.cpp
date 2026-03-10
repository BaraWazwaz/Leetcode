class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 1e7, ans = 0;
        for (auto& x : prices) {
            ans = max(ans, x - buy);
            buy = min(buy, x);
        }
        return ans;
    }
};