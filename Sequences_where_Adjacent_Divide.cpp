class Solution {
  public:
    int mod = 1e9 + 7;
    int dp[1001][1001]; // Adjust size according to maximum N and M constraints

    int solve(int val, int cnt, int n, int m) {
        // Base Case: If we have formed an array of size N
        if (cnt == n) {
            return 1;
        }

        // Return memoized result if already calculated
        if (dp[cnt][val] != -1) {
            return dp[cnt][val];
        }

        long long res = 0;

        // 1. Find all multiples of 'val' up to M
        for (int i = val; i <= m; i += val) {
            res = (res + solve(i, cnt + 1, n, m)) % mod;
        }

        // 2. Find all factors of 'val' (excluding 'val' itself since it was covered in multiples)
        for (int i = 1; i * i <= val; i++) {
            if (val % i == 0) {
                // 'i' is a factor
                if (i != val) {
                    res = (res + solve(i, cnt + 1, n, m)) % mod;
                }
                // 'val / i' is also a factor
                if (val / i != val && val / i != i) {
                    res = (res + solve(val / i, cnt + 1, n, m)) % mod;
                }
            }
        }

        return dp[cnt][val] = res;
    }

    int count(int n, int m) {
        // Reset the DP table with -1
        memset(dp, -1, sizeof(dp));

        long long totalArrays = 0;
        // The first element can be any number from 1 to M
        for (int i = 1; i <= m; i++) {
            totalArrays = (totalArrays + solve(i, 1, n, m)) % mod;
        }

        return totalArrays;
    }
};
