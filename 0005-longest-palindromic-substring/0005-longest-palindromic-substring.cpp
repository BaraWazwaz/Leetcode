class Solution {
    string* str;
    int start, length, n;
    void check(int i, int j) {
        while (0 <= i && j < n)
            if ((*str)[i] == (*str)[j])
                --i, ++j;
            else
                break;
        ++i, --j;
        int len = j - i + 1;
        if (len > length) {
            length = len;
            start = i;
        }
    }
public:
    string longestPalindrome(string s) {
        str = &s;
        start = 0;
        length = 1;
        n = s.size();
        for (int i = 0; i < n; ++i)
            check(i, i);
        for (int i = 1; i < n; ++i)
            check(i - 1, i);
        return s.substr(start, length);
    }
};