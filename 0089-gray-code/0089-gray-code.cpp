class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int N = 1ull << n;
        ans.reserve(N);
        for (int i = 0; i < N; ++i)
            ans.push_back(i ^ (i >> 1));
        return ans;
    }
};