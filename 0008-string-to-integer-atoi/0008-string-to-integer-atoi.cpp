class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (i < s.size() && s[i] == ' ')
            ++i;
        bool sign = i >= s.size() || s[i] != '-';
        i += i < s.size() && 
             (s[i] == '+' || s[i] == '-');
        const long long mask = 1ll << 32, 
                        pos = (1ll << 31) - 1, 
                        neg = -(1ll << 31);
        long long value = 0;
        bool outside = false;
        while (i < s.size() && !outside &&
               '0' <= s[i] && s[i] <= '9') {
            value *= 10;
            value += s[i] - '0';
            outside = (int)value != value;
            ++i;
        }
        value *= (sign * 1 + !sign * -1);
        outside = (int)value != value;
        return !outside * value + 
               outside * (sign * pos + !sign * neg);
    }
};