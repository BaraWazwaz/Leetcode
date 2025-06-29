class Solution {
public:
    int reverse(int x) {
        long long input = x;
        long long ans = 0;
        bool minus = input < 0;
        input = abs(input);
        while (input)
            ans *= 10, ans += input % 10, input /= 10;
        if (minus)
            ans *= -1;
        if ((int)(ans) != ans)
            return 0;
        else
            return ans;
    }
};