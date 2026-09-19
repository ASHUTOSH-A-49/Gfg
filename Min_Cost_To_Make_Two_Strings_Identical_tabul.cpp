class Solution {
  public:
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        // code here
        int m = s1.size(),n = s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (s1[i-1] == s2[j - 1]) {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
        int len = dp[m][n];
        int ans = costS1*(m-len)+costS2*(n-len);
        return ans;
        
    }
};
