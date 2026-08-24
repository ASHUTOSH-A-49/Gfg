class Solution {
  public:
    int prefixStrings(int n) {
        // code here
        int mod = 1000000007;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        if (n >= 1)
            dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {

            long long res = 0;

            for (int j = 0; j < i; j++)
            {
                res = (res + 1LL * dp[j] * dp[i - j - 1]) % mod;
            }

            dp[i] = (int)res;
        }

        return dp[n];
    }
};
