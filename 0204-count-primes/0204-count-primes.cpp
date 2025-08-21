class Solution {
public:
    vector <int> primes;
    void seive(int n) {
        primes.assign(n + 1, 1);
        primes[0] = primes[1] = 0;
        for (int i = 2; i <= n; ++i) {
            if (!primes[i])
                continue;
            for (int j = i + i; j <= n; j += i)
                primes[j] = 0;
        }
    }
    int countPrimes(int n) {
        if (n < 2)
            return 0;
        seive(n);
        return accumulate(primes.begin(), primes.end() - 1, 0);
    }
};