class Solution {
    void radixSort(std::vector<int>& arr) {
        if (arr.empty()) return;

        int n = arr.size();
        std::vector<int> output(n);
        long long max_val = *std::max_element(arr.begin(), arr.end());

        // Process 8 bits (1 byte) at a time
        for (unsigned int shift = 0; (max_val >> shift) > 0; shift += 8) {
            int count[256] = {0};

            // Store count of occurrences in count[]
            for (int i = 0; i < n; i++)
                count[(arr[i] >> shift) & 0xFF]++;

            // Change count[i] so that it contains actual position
            for (int i = 1; i < 256; i++)
                count[i] += count[i - 1];

            // Build the output array (stable sort)
            for (int i = n - 1; i >= 0; i--) {
                output[count[(arr[i] >> shift) & 0xFF] - 1] = arr[i];
                count[(arr[i] >> shift) & 0xFF]--;
            }

            // Copy output back to arr
            arr = output;
        }
    }
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
        radixSort(nums);
        for (int i = 1; i < nums.size(); ++i)
            ans = max(ans, nums[i] - nums[i - 1]);
        return ans;
    }
};