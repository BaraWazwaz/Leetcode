class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans (rowIndex + 1, 1);
        for (int i = 0; i < rowIndex; ++i)
            ans[i + 1] = (long long)ans[i] * (rowIndex - i) / (i + 1);
        return ans;
    }
};