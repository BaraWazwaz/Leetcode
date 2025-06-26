class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int last = nums.size() - 1;
        while (last > 0 and nums[last] == val)
            --last;
        for (int i = 0; i <= last; ++i)
            if (nums[i] == val) {
                swap(nums[i], nums[last]);
                --last;
                while (last > 0 and nums[last] == val)
                    --last;
            }
        nums.resize(last + 1);
        return last + 1;
    }
};