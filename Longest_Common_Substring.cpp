class Solution {
  public:
    int longCommSubstr(string& text1, string& text2) {
        // code here
        int m = text1.size(),n = text2.size();
                vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
                int maxlen = 0;
                for (int i = 1; i <= m; i++) {
                    for (int j = 1; j <= n; j++) {
                        //only match step would increment dp val else it will be again 0
                        if (text1[i - 1] == text2[j - 1]) {
                            dp[i][j] = 1 + dp[i - 1][j - 1];
                        } 
                        maxlen = max(maxlen,dp[i][j]);
                    }
                }
                return maxlen;
    }
};
