class Solution {
  public:
  int INF = 1e8;

    int minOperation(int n) {
        // code here
        if (n == 0) return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int add = 1 + dp[i - 1];
            int twice = INF;
            if (i % 2 == 0) {
                twice = 1 + dp[i / 2];
            }
            dp[i] = min(add, twice);
        }
        return dp[n];
    }
};
