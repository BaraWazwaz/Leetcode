class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, ans = 0, n = s.size();
        set<char> st;
        while (right < n) {
            if (!st.count(s[right])) {
                st.insert(s[right]);
                ++right;
            }
            else {
                ans = max(ans, right - left);
                while (left < right) {
                    st.erase(s[left]);
                    ++left;
                    if (s[left - 1] == s[right])
                        break;
                }
                st.insert(s[right]);
                ++right;
            }
        }
        ans = max(ans, right - left);
        return ans;
    }
};