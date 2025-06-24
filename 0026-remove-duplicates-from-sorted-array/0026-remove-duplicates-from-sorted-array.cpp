class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<bool> v (201, 0);
        for (auto &num : nums)
            v[num + 100] = true;
        nums.clear();
        for (int i = 0; i < 201; ++i)
            if (v[i])
                nums.push_back(i - 100);
        return nums.size();
    }
};