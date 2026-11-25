class Solution {
  public:
    long long MOD = 1000000007;
    long long solve(int a, int b, int c, int d)
    {
        int remaining = d - c;

        if (remaining <= 0)
            return 1;

        if (remaining <= a)
            return remaining + 1;

        int net = a - b;
        long long distance = remaining - a;
        long long cycles = (distance + net - 1) / net;

        return remaining + 2LL * b * cycles + 1;
    }
    long long summ(int a, int b, long long t)
    {
        long long first = a + 2;
        long long cycleTime = a + b;

        if (t < first)
            return 0;

        long long count = (t - first) / cycleTime + 1;
        long long last = first + (count - 1) * cycleTime;

        long long term1 = (b % MOD) * (count % MOD) % MOD;
        term1 = term1 * ((first + last) % MOD) % MOD;

        long long term2 = (count % MOD) * (2LL * b - 1) % MOD;
        term2 = term2 * (2LL * b) % MOD;
        term2 = term2 * ((MOD + 1) / 2) % MOD;

        return (term1 + term2) % MOD;
    }
    long long prefix(int a, int b, long long t)
    {
        long long total = (t % MOD) * ((t + 1) % MOD) % MOD;
        total = total * ((MOD + 1) / 2) % MOD;

        return (total - summ(a, b, t) + MOD) % MOD;
    }
    int minTime(int a, int b, int d, int l, int r)
    {
        long long t1 = solve(a, b, l, d);
        long long t2 = solve(a, b, r + 1, d);

        return (prefix(a, b, t1) - prefix(a, b, t2) + MOD) % MOD;
    }


};
